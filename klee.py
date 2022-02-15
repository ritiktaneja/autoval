import enum
from genericpath import isfile
import os,re

class KleeResponses(enum.Enum):
    EQUIVALENT = 1
    NOT_EQUIVALENT = 0
    ASSERTION_FAIL = -1
    TIME_LIMIT_EXCEEDED = -2

class Klee:
    def __init__(self,max_time="10s",max_solver_time="20s",exit_on_error_type="Assert"):
        self.max_time = max_time
        self.max_solver_time = max_solver_time
        self.exit_on_error_type="Assert"
    
    def run(self,program_path):
        try:
            if not isfile(program_path):      
                raise Exception("Program File Not Found")
            os.system("clang -emit-llvm -c "+program_path+" 2> temp.txt")
            
            output = open("temp.txt","r").read()

            if len(re.findall(r": error:",output)) != 0 or not isfile("temp.bc"):
                print(output)
                raise Exception("Program Compilation Failed")

            os.system("rm temp.txt")
            
            os.system("klee --max-time="+self.max_time+" --max-solver-time="+self.max_solver_time+" --exit-on-error-type="+self.exit_on_error_type+" temp.bc 2> temp.txt")
            output = open("temp.txt","r").read()
            
            os.system("rm temp.txt")

            if len(re.findall(r"ASSERTION FAIL",output)) != 0 or len(re.findall(r"ERROR",output)) != 0:
                return KleeResponses.ASSERTION_FAIL
               
            if len(re.findall(r"HaltTimer",output)) != 0:
                return KleeResponses.TIME_LIMIT_EXCEEDED
               
            os.system("rm temp.bc\nrm -r klee-out-0\nrm klee-last")

        except Exception as e:
            print(e)
    