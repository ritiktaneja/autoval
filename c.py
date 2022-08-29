from asyncio import subprocess
from copy import deepcopy
import ctypes
from fileinput import filename

import multiprocessing

from multiprocessing.pool import Pool


from ctypes import CDLL
from ctypes import *
from genericpath import isfile
import os
import re
import string

from config import general
import util_tools as ut
class c:
    def __init__(self):
        self.function_name = general.solution_function_name
        self.function_type = general.solution_function_type
        self.output_dir = os.path.abspath(general.output_dir)


    def run_func(self,filepath,entry_point,*arg_vals):
        
        try:
            lib = CDLL(filepath)    
            args=[]

            for x in arg_vals:
                args.append(c_int64(x))
            
            func_name = entry_point
            lib[func_name].argtypes=[ctypes.c_int,ctypes.c_int,ctypes.c_int,ctypes.c_int]
            output = lib[func_name](*args)
            print("\t output of",os.path.basename(filepath),"[",arg_vals,"] is ",output)
            return {"output":output,"error":False}
        except Exception as e:
            #raise Exception(e)
            print(e)
            return {"error" : True,"output":e}



    def build_so(self,filepath):
        cwd = os.getcwd()
        try:
            runner_dir = "runner"
            filepath = os.path.abspath(filepath)
            os.chdir(general.output_dir)
            if(runner_dir not in os.listdir()):
                os.mkdir(runner_dir)
            os.chdir(runner_dir)

            name = os.path.basename(filepath)+".so"

            if isfile(name):
                os.system("rm -r "+name)
                
            os.system("cc -fPIC -shared -o "+name+" "+filepath)
            return os.path.abspath(name)
        except Exception as e:
            raise Exception(e)
        finally:
            os.chdir(cwd)

   

    # def build_combilned_so(self,solution1_path,solution2_path,filename="temp.c"):
    #     cwd = os.getcwd()
    #     try:
    #         if not(isfile(solution1_path) and isfile(solution2_path)):
    #             print("Invalid File Path")
    #             return 

    #         solution1 = open(solution1_path,"r").read()
    #         solution2 = open(solution2_path,"r").read()
            
    #         solution1 = re.sub(self.function_name,self.function_name+"1",solution1,count=0)
    #         solution2 = re.sub(self.function_name,self.function_name+"2",solution2,count=0)

    #         runner_func = self.__build_runner_func()
           
    #         os.system("rm -f "+filename)
    #         temp_file = open(filename,"a+")
    #         temp_file.write("// File1 : "+os.path.basename(solution1_path)+" File2 : "+os.path.basename(solution2_path)+"\n")
    #         temp_file.write("#include<stdio.h>\n#include<stdlib.h>\n#include<assert.h>\n#include<string.h>\n\n")
    #         temp_file.write(solution1+"\n\n\n")
    #         temp_file.write(solution2+"\n\n\n")
    #         temp_file.write(runner_func)
    #         temp_file.close()

    #         cwd = os.getcwd()
           
    #         runner_dir = "runner_dir"
    #         filepath = os.path.abspath(filename)
            
    #         os.chdir(self.output_dir)
    #         if(runner_dir not in os.listdir()):
    #             os.mkdir(runner_dir)
    #         os.chdir(runner_dir)

    #         name = os.path.basename(filepath)+".out"

    #         if isfile(name):
    #             os.system("rm -r "+name)
                
    #         os.system("cc -fPIC -shared -o "+name+" "+filepath)
    #         return os.path.abspath(name)
            
    #     except Exception as e:
    #         print("Error in building so : ",e)
    #     finally:
    #         os.chdir(cwd)


# 6018.c 19309.c
       


    
if __name__ == "__main__" :
    solutions_dir = general.solutions_dir
    for solution in os.listdir(solutions_dir):
        path = os.path.join(solutions_dir, solution)
        os.system("gcc -Wall "+path)
        


    