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

class CbmcResponses(enum.Enum):
    SUCCESS = 1
    FAILED = 0
    TIME_LIMIT_EXCEEDED = -1
    UNDEFINED = -2



class CbmcError(Exception):
    pass


class Cbmc:
    '''
        Initlialize Cbmc class object with the flags you want to set while calling cbmc functions. 
        cbmc should be a string and will be appended as it is during cbmc system call.
    '''
    def __init__(self,cbmc_flags=""):
        # TODO sanitize cbmc_flags input
        try:
            self.function_name = general.solution_function_name
            self.function_type = general.solution_function_type
            self.output_dir = os.path.abspath(general.output_dir)
            self.filename = "temp.c"
            #self.scalar_args_fp = os.path.abspath("./config/scalar_args.txt")
            self.cbmc_flags = cbmc_flags
        except Exception as e:
            print(e)

    '''
        Decorator to check whether required libraries are installed in the system or not.
    '''
    def check_sys_dependencies(func):
        dependencies = ['cbmc']
        for d in dependencies:
            status,res = subprocess.getstatusoutput(d)
            if(status == 127):
                raise CbmcError(res)
        return func

    '''
        Method to perfrom cbmc system call. Both parameters filename and output_dir are mandatory.
    '''
    @check_sys_dependencies
    def __run(self,filename,output_dir = ""):
        
        program_path = os.path.abspath(filename)
        try:
          
            cwd = os.getcwd()
               
            if not isdir(output_dir):
                raise CbmcError("Output Directory Not Found")
            
            self.output_dir = os.path.abspath(output_dir)
            #os.chdir(self.output_dir)
            
            if not isfile(program_path):      
                raise CbmcError("Program File Not Found")
           
            print("\n ------ Running CBMC Engine------\n\n ")
            os.system("rm temp.txt")    
            cmd = "cbmc "+self.cbmc_flags+" "+program_path+"> temp.txt"
            print(cmd)
            
            os.system(cmd)
           
            if not isfile("temp.txt"):
                print("Unable to find txt")
               
            output = open("temp.txt","r").read()
            
            
            if len(re.findall(r"FAILURE",output)) != 0:
                return CbmcResponses.FAILED
            if len(re.findall(r"SUCCESS",output)) != 0:
                return CbmcResponses.SUCCESS
            
            print("here")
            sys.exit(0)
            return CbmcResponses.UNDEFINED
      
        except CbmcError as e:
            print("err",e)
        finally:
            os.chdir(cwd)

  

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
         
            main_method = self.__build_cbmc_main(self.function_type,self.function_name+"1",self.function_name+"2")
            
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

    def __build_cbmc_main(self,function_type,function1_name,function2_name)-> string:
            main_method = "int nondet_int();\n\n int main()\n{\n\t"

            scalar_arguments_dict = ut.get_scalar_argument_list()
            #print("Scalar Arguments : ",scalar_arguments_dict)
            
            parameters=""
           
            for x in scalar_arguments_dict:
                type,name,value = scalar_arguments_dict[x]
                if value.isnumeric():
                    main_method = main_method + type + " " + name + " = " + value + ";\n\n\t"
                else: 
                    main_method+= type+" "+ name + " = "+"nondet_"+type+"();\n\n\t __CPROVER_assume("+name+">0);\n\t" 

                  
                
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
        response  = self.__run(filename=filename,output_dir = self.output_dir)
        return response




        



    