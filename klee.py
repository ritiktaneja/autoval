import struct
import subprocess
import enum
from genericpath import isdir, isfile
import os,re
import sys

class KleeResponses(enum.Enum):
    SUCCESS = 1
    TIME_LIMIT_EXCEEDED = -2


class KleeError(Exception):
    pass


class Klee:
    def __init__(self,max_time="10s",max_solver_time="10s",exit_on_error_type="Assert"):
        self.max_time = max_time
        self.max_solver_time = max_solver_time
        self.exit_on_error_type=exit_on_error_type


    def check_sys_dependencies(func):
        dependencies = ['clang','klee -help']
        for d in dependencies:
            status,res = subprocess.getstatusoutput(d)
            if(status == 127):
                raise KleeError(res)
        return func

    @check_sys_dependencies
    def run(self,filename,output_dir):

        program_path = os.path.abspath(filename)
        try:
            print("\n ------ Running Klee Engine------\n\n ")
            cwd = os.getcwd()
               
            if not isdir(output_dir):
                raise KleeError("Output Directory Not Found")
            
            self.output_dir = os.path.abspath(output_dir)
            os.chdir(self.output_dir)
            
            if not isfile(program_path):      
                raise KleeError("Program File Not Found")
          
            os.system("clang -emit-llvm  -c "+program_path+" -o temp.bc 2> temp.txt")
            output = open("temp.txt","r").read()
            if len(re.findall(r": error:",output)) != 0 or not isfile("temp.bc"):
                print(output)
                raise KleeError("Program Compilation Failed")

            os.system("rm temp.txt")
            
            os.system("klee --max-time="+self.max_time+" --max-solver-time="+self.max_solver_time+" temp.bc 2> temp.txt")
            output = open("temp.txt","r").read()

            if len(re.findall(r"HaltTimer",output)) != 0:
                print("Potential Divergence")
                return KleeResponses.TIME_LIMIT_EXCEEDED
            
            return KleeResponses.SUCCESS
        except KleeError as e:
            print(e)
        finally:
            os.system("cp "+program_path+" ./klee-last/")
            os.chdir(cwd)


    def get_result_object(self,dir_path):
        cwd = os.getcwd()
        try:
            if not isdir(dir_path):
                raise Exception("Klee output not found. :",dir_path )
        
            klee_out_dir = os.path.abspath(dir_path)+"/klee-last/"
            
            os.chdir(klee_out_dir)
            result = []
            for file_path in os.listdir(klee_out_dir):
                if file_path.endswith(".err"):
                        testcase = dict()
                        name = testcase['name'] = file_path.split(".")[0]
                        err_type = file_path.split(".")[1]
                        tf_filename = name+".ktest"
                        testcase['objects'] = self.get_objects_from_file_path(tf_filename)
                        testcase['error_type'] = err_type
                        result.append(testcase)
            return result
        finally:
            os.chdir(cwd)   
        

    def get_objects_from_file_path(self,path):
        try:
            f = open(path, 'rb')
        except IOError:
            print('ERROR: file %s not found' % path)
            sys.exit(1)
            
        hdr = f.read(5)
        if len(hdr) != 5 or (hdr != b'KTEST' and hdr != b'BOUT\n'):
            raise KleeError('unrecognized file')

        version, = struct.unpack('>i', f.read(4))
        # if version > version_no:
        #     raise KTestError('unrecognized version')

        numArgs, = struct.unpack('>i', f.read(4))
        args = []
        for i in range(numArgs):
            size, = struct.unpack('>i', f.read(4))
            args.append(str(f.read(size).decode(encoding='ascii')))

        if version >= 2:
            symArgvs, = struct.unpack('>i', f.read(4))
            symArgvLen, = struct.unpack('>i', f.read(4))
        else:
            symArgvs = 0
            symArgvLen = 0

        numObjects, = struct.unpack('>i', f.read(4))
        objects = dict()
        
        for i in range(numObjects):
            size, = struct.unpack('>i', f.read(4))
            name = f.read(size).decode('utf-8')
            size, = struct.unpack('>i', f.read(4))
            bytes = f.read(size)
            # mydict = dict()
            # mydict['name'] = name
            #mydict['byte'] = bytes
            # mydict['int'] = struct.unpack('i',bytes)[0] 
            objects[name] = struct.unpack('i',bytes)[0] 
        
            # objects.append(mydict)
        return objects
    



# Symboilic Variables * Output for each cluster

# a=1,b=2  c1=5,c2=6
# a=2,b=3    


#res = myKlee.get_result_object("myoutput2")

#print(res)




    