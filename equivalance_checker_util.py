from genericpath import isfile
from operator import ge
import os,sys
import re
import string

from config import general as gen_config



class equivalance_checker_util():

    def __init__(self,function_name,function_type):
        self.function_name = function_name
        self.function_type = function_type
        self.filename = "temp.c"
        self.scalar_args_fp = os.path.abspath("./config/scalar_args.txt")

    def build_program(self,solution1_path, solution2_path,filename="temp.c") -> int:
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

            main_method = self.build_klee_main(self.function_type,self.function_name+"1",self.function_name+"2")
            
            os.system("rm -f "+filename)
            temp_file = open(filename,"a+")
            temp_file.write("// File1 : "+os.path.basename(solution1_path)+" File2 : "+os.path.basename(solution2_path)+"\n")
            temp_file.write("#include<stdio.h>\n#include<stdlib.h>\n#include<assert.h>\n#include<string.h>\n\n")
            temp_file.write(solution1+"\n\n\n")
            temp_file.write(solution2+"\n\n\n")
            temp_file.write(main_method)
            temp_file.close()
            return 
        except:
            print("Error")
        finally:
            os.chdir(cwd)


    def build_klee_main(self,function_type,function1_name,function2_name)-> string:
            main_method = "int main()\n{\n\t"

            scalar_arguments_dict = self.get_scalar_argument_list()
            #print("Scalar Arguments : ",scalar_arguments_dict)

            parameters=""

            for x in scalar_arguments_dict:
                type,name,value = scalar_arguments_dict[x]
                if value.isnumeric():
                    main_method = main_method + type + " " + name + " = " + value + ";\n\n\t"
                else:
                    main_method = main_method + type + " " + name + ";\n\tklee_make_symbolic(&" + name + ",sizeof(" + name + "),\"" + name + "\");\n\tklee_assume("+ name+ " > 0); \n\t"
                    # main_method = main_method + type + " " + name + ";\n\tklee_make_symbolic(&" + name + ",sizeof(" + name + "),\"" + name + "\");\n\n\t"
                
                parameters = parameters + "," + name
            
            parameters = parameters[1:]
            
        # print(parameters)

            main_method = main_method + function_type + " return_value_1 = " + function1_name + "(" + parameters + ");\n\t"
            main_method = main_method + function_type + " return_value_2 = " + function2_name + "(" + parameters + ");\n\n\t"

            main_method = main_method + "assert(return_value_1 == return_value_2); \n\n"
            main_method = main_method + "\treturn 0; \n }"
            
            return main_method

    def get_scalar_argument_list(self):
        # Parse config file
        config_file = open(self.scalar_args_fp,"r")
        config_file_lines = config_file.readlines()

        for i in range(len(config_file_lines)):
            config_file_lines[i] = config_file_lines[i].strip()

        argument_list = {}
        count = 1
        data_types = ["int","float","double","char"]
        for x in config_file_lines:
            tokens = x.split()
            if len(tokens) > 3 or len(tokens) < 2:
                sys.stderr.write("Invalid Scalar Config Format\n")
                exit()
            if tokens[0].strip() not in data_types:
                sys.stderr.write("Invalid Input Data Type\n")
                exit()
            if len(tokens) == 3:
                if tokens[0].strip() == "char":
                    if tokens[2].strip().endswith("'") == False or tokens[2].strip()[0] != "'":
                        sys.stderr.write("Enclose character values within single quotes\n")
                        exit()
                argument_list[count] = (tokens[0].strip(),tokens[1].strip(),tokens[2].strip())
            else:
                argument_list[count] = (tokens[0].strip(),tokens[1].strip(),"NaN")
            count = count + 1
        
        return argument_list

