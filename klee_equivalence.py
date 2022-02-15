from genericpath import isfile
from operator import ge
import os
import re
import tempfile
import klee_main_builder
from RESPONSE_CODES import Response
from config import general as config


def check_equivalance(solution1_path, solution2_path) -> int:
    

    if not(isfile(solution1_path) and isfile(solution2_path)):
        print("Invalid File Path")
        return Response.INVALID_FILE_PATH
    
    solution1 = open(solution1_path,"r").read()
    solution2 = open(solution2_path,"r").read()
    
    solution1 = re.sub(config.solution_function_name,config.solution_function_name+"1",solution1,count=0)
    solution2 = re.sub(config.solution_function_name,config.solution_function_name+"2",solution2,count=0)

    main_method = klee_main_builder.equivalence_main(config.solution_function_type,config.solution_function_name+"1",config.solution_function_name+"2")
    
    #TODO Remove Main Function if Present in Solution Files

    os.system("rm -f temp.c")
    temp_file = open("temp.c","a+")
    temp_file.write("#include<stdio.h>\n#include<stdlib.h>\n#include<assert.h>\n#include<string.h>\n\n")
    temp_file.write(solution1+"\n\n\n")
    temp_file.write(solution2+"\n\n\n")
    temp_file.write(main_method)
    temp_file.close()

    os.system("clang -emit-llvm -c temp.c 2> temp.txt")
    output = open("temp.txt","r").read()

    if len(re.findall(r": error:",output)) != 0:
        return Response.COMPILE_TIME_ERROR
    
    os.system("rm temp.txt")
    os.system("rm temp.c")

    if len(re.findall(r": error:",output)) != 0:
        print("Compile Time Error Found")
        return Response.COMPILE_TIME_ERROR

    os.system("klee --max-time=20s  --max-solver-time=20s --exit-on-error-type=Assert temp.bc 2> temp.txt")
    output = open("temp.txt","r").read()
    os.system("rm temp.txt")
    if len(re.findall(r"ASSERTION FAIL",output)) != 0 or len(re.findall(r"ERROR",output)) != 0:
        os.system("rm temp.bc\nrm -r klee-out-0\nrm klee-last")
        return Response.NOT_EQUIVALENT

    if len(re.findall(r"HaltTimer",output)) != 0:
        os.system("rm temp.bc\nrm -r klee-out-0\nrm klee-last")
        print("TLE")
        return Response.TIME_LIMIT_EXCEEDED
  
    os.system("rm temp.bc\nrm -r klee-out-0\nrm klee-last")

    return Response.EQUIVALENT
