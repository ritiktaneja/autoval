from asyncio import subprocess
from copy import deepcopy
import multiprocessing

from multiprocessing.pool import Pool


from ctypes import CDLL
from ctypes import *
from genericpath import isfile
import os
import string
from unittest import runner


from config import general as gconfig
from equivalance_checker_util import equivalance_checker_util


class c:
    # @staticmethod
    # def runner(filepath,*arg_vals):
       
            

    def run_func(filepath,*arg_vals):
        
        try:
            lib = CDLL(filepath)    
            args=[]
            for x in arg_vals:
                args.append(c_int64(x))

            func_name = gconfig.solution_function_name
            output = lib[func_name](*args)
            
            return {"output":output}
        except:
            print("Run Time Error")


    def build_so(filepath):
        cwd = os.getcwd()
        try:
            runner_dir = "runner"
            filepath = os.path.abspath(filepath)
            os.chdir(gconfig.output_dir)
            if(runner_dir not in os.listdir()):
                os.mkdir(runner_dir)
            os.chdir(runner_dir)

            name = os.path.basename(filepath)+"."

            if isfile(name):
                os.system("rm -r "+name)
                
            os.system("cc -fPIC -shared -o "+name+" "+filepath)
            return os.path.abspath(name)

        finally:
            os.chdir(cwd)

   



    