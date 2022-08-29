import string
import struct
import subprocess
import enum
from genericpath import isdir, isfile
import os,re
import sys
from testcases_util import testcases_util
import util_tools as ut
from config import general 

class KleeResponses(enum.Enum):
    EQUIVALENT= 2
    SUCCESS = 1
    NOT_EQUIVALENT = 0
    TIME_LIMIT_EXCEEDED = -2


class KleeError(Exception):
    pass


class Klee:
    '''
        Initlialize Klee class object with the flags you want to set while calling klee functions. 
        klee_flags should be a string and will be appended as it is during klee system call.
    '''
    def __init__(self,klee_flags=""):
        # TODO sanitize klee_flags input
        try:
            self.function_name = general.solution_function_name
            self.function_type = general.solution_function_type
            self.output_dir = os.path.abspath(general.output_dir)
            self.filename = "temp.c"
            #self.scalar_args_fp = os.path.abspath("./config/scalar_args.txt")
            self.klee_flags = klee_flags
        except Exception as e:
            print(e)

    '''
        Decorator to check whether required libraries are installed in the system or not.
    '''
    def check_sys_dependencies(func):
        dependencies = ['clang']
        for d in dependencies:
            status,res = subprocess.getstatusoutput(d)
            if(status == 127):
                raise KleeError(res)
        return func

    '''
        Method to perfrom klee system call. Both parameters filename and output_dir are mandatory.
    '''
    @check_sys_dependencies
    def __run(self,filename,output_dir = ""):
        program_path = os.path.abspath(filename)
        try:
          
            cwd = os.getcwd()
               
            if not isdir(output_dir):
                raise KleeError("Output Directory Not Found")
            
            self.output_dir = os.path.abspath(output_dir)
            os.chdir(self.output_dir)
            
            if not isfile(program_path):      
                raise KleeError("Program File Not Found")
            print("\n ------ Compiling Klee File ------\n\n ")

            os.system("clang -emit-llvm  -c "+program_path+" -o temp.bc 2> temp.txt")
            
            output = open("temp.txt","r").read()
            if len(re.findall(r": error:",output)) != 0 or not isfile("temp.bc"):
                raise KleeError("Program Compilation Failed : ",output)

            os.system("rm temp.txt")
            print("\n ------ Running Klee Engine------\n\n ")
            cmd = "klee "+self.klee_flags+" temp.bc 2> temp.txt"
            #print(cmd)
            os.system(cmd)
            os.system("cp "+program_path+" ./klee-last/")
            
            output = open("temp.txt","r").read()
            if len(re.findall(r"HaltTimer",output)) != 0:
                print("Potential Divergence")
                return KleeResponses.TIME_LIMIT_EXCEEDED

            return KleeResponses.SUCCESS
      
        except KleeError as e:
            print("err",e)
        finally:
           
            os.chdir(cwd)

    '''
        Method to fetch testcases from the 'klee-last' subfolder present in the directory given in parameter.
        on passing err_only=True, only those testcases which result in an error will be considered.
    '''
    def get_result_object(self,dir_path="",err_only=True):
        
        if(dir_path == ""):
            dir_path = self.output_dir
        cwd = os.getcwd()
        try:
            if not isdir(dir_path):
                raise Exception("Klee output not found. :",dir_path )
            klee_out_dir = os.path.abspath(dir_path)+"/klee-last/"
            
            os.chdir(klee_out_dir)
            result = []
            for file_path in os.listdir(klee_out_dir):
                if  (err_only and file_path.endswith(".err")) or (err_only ==False and file_path.endswith(".ktest")):
                        testcase = dict()
                        name = testcase['name'] = file_path.split(".")[0]
                        ext = file_path.split(".")[1]
                        tf_filename = name+".ktest"
                        testcase['objects'] = self.__get_objects_from_file_path(tf_filename)
                        testcase['test_case_type'] = ext
                        result.append(testcase)
            
            if (len(result) == 0):
                output = open("warnings.txt","r").read()
                if len(re.findall(r"KLEE: ERROR:",output)) != 0:
                    print("here")
                    testcase = dict()
                    testcase['objects'] = output
                    testcase['test_case_type'] = "warnings.txt"
                    result.append(testcase)
                    
            return result
        except KleeError as e:
            print("err",e)
        finally:
            os.chdir(cwd)   
        

    def __get_objects_from_file_path(self,path):
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
    

    def __build_program(self,solution1_path, solution2_path,filename="temp.c") -> int:
        try:
            cwd = os.getcwd()
            # os.chdir(output_dir)
            if not(isfile(solution1_path) and isfile(solution2_path)):
                print("Invalid File Path")
                return 
            solution1 = open(solution1_path,"r").read()
            solution2 = open(solution2_path,"r").read()
            
            solution1 = re.sub(self.function_name,self.function_name+"1",solution1,count=0)
            solution2 = re.sub(self.function_name,self.function_name+"2",solution2,count=0)
         
            main_method = self.__build_klee_main(self.function_type,self.function_name+"1",self.function_name+"2")
            
            os.system("rm -f "+filename)
            temp_file = open(filename,"a+")
            temp_file.write("// File1 : "+os.path.basename(solution1_path)+" File2 : "+os.path.basename(solution2_path)+"\n")
            temp_file.write("#include<stdio.h>\n#include<stdlib.h>\n#include<assert.h>\n#include<string.h>\n\n")
            temp_file.write(solution1+"\n\n\n")
            temp_file.write(solution2+"\n\n\n")
            temp_file.write(main_method)
            temp_file.close()
            
            return 
        except Exception as e:
            print(e)
        finally:
            os.chdir(cwd)

    def __build_klee_main(self,function_type,function1_name,function2_name)-> string:
            main_method = "int main()\n{\n\t"

            scalar_arguments_dict = ut.get_scalar_argument_list()
            #print("Scalar Arguments : ",scalar_arguments_dict)
            
            parameters=""
           
            for x in scalar_arguments_dict:
                type,name,value = scalar_arguments_dict[x]
                if value.isnumeric():
                    main_method = main_method + type + " " + name + " = " + value + ";\n\n\t"
                else:
                    main_method = main_method + type + " " + name + ";\n\tklee_make_symbolic(&" + name + ",sizeof(" + name + "),\"" + name + "\");\n\tklee_assume("+ name+ " > 0); \n\tklee_assume("+ name+ " < 65536); \n\t"
                    # main_method = main_method + type + " " + name + ";\n\tklee_make_symbolic(&" + name + ",sizeof(" + name + "),\"" + name + "\");\n\n\t"
                
                parameters = parameters + "," + name
            
            parameters = parameters[1:]
        # print(parameters)

            main_method = main_method + function_type + " return_value_1 = " + function1_name + "(" + parameters + ");\n\t"
            main_method = main_method + function_type + " return_value_2 = " + function2_name + "(" + parameters + ");\n\n\t"

            main_method = main_method + "assert(return_value_1 == return_value_2); \n\n"
            main_method = main_method + "\treturn 0; \n }"
            
            return main_method

    

    def check_equivalence(self,solution1_path,solution2_path):
        filename = "temp.c"
        self.__build_program(solution1_path=solution1_path,solution2_path=solution2_path,filename=filename)
        response = self.__run(filename=filename,output_dir = self.output_dir)
        result = self.get_result_object(self.output_dir,err_only=True) 
        if (len(result)>0):      
            #testcases_util().push_testcases(testcases=result)
            return KleeResponses.NOT_EQUIVALENT
    
        if response == KleeResponses.SUCCESS:
            return KleeResponses.EQUIVALENT
        
        return response




if __name__ == "__main__":
    if(len(sys.argv) < 3):
        print("Invalid format")
        sys.exit()
    myKlee = Klee(klee_flags="-max-time=10s -exit-on-error")
    solution1_path = sys.argv[1]
    solution2_path = sys.argv[2]
    kleeResponse = myKlee.check_equivalence(solution1_path,solution2_path)
    print(kleeResponse)
# ## Sample exection
# myKlee = Klee(klee_flags="-max-time=5s -exit-on-error")

# myKlee.run("temp.c",os.getcwd())
# res = myKlee.get_result_object(os.getcwd(),err_only=True)

# print(res)




    