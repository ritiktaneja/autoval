from genericpath import isfile
from random import randint
import re
import string
import sys
import pandas as pd
from config import general
import util_tools as ut
from ctypes import CDLL
import ctypes
import os
from c import c

class testcases_util:
    def __init__(self) -> None:
        self.function_name = general.solution_function_name 
        self.function_type = general.solution_function_type   
        self.testcases_file = os.path.abspath(general.testcases_file)
        self.runner_function_name = "runner"
        self.output_dir = os.path.abspath(general.output_dir)
        self.runner_dir = "combined"
        pass
        
    
    def push_testcases(self,testcases):
        try:
            df = pd.read_csv(self.testcases_file)
        except:
            df = pd.DataFrame()
        arg_list = ut.get_scalar_argument_list()
        data=[]

        for testcase in testcases:
            data.append(testcase['objects'])

        var_names = []

        for indx in arg_list:
            var_names.append(arg_list[indx][1])
        df = df.append(pd.DataFrame(data))
        df.drop_duplicates(subset=var_names,inplace=True, keep='first')
        df.to_csv(self.testcases_file,index=False)  

        
        
              # for testcase in testcases:
        #     testcase = testcase['objects']




    
    # def __run_test_cases(self,filepath1,clustered_solution,cluster_name):
    #         try:
    #             df = pd.read_csv(self.testcases_file)
    #         except:
    #             df = pd.DataFrame()
    #         flag = True
    
    #         param_list=ut.get_scalar_argument_list()
    #         params = []
    #         try:
    #             for key,indx in enumerate(param_list):
    #                 params.append(param_list[indx][1])

    #             file1_so = c.build_so(filepath1)
    #             file2_so = c.build_so(clustered_solution)

    #             for idx,data in df.iterrows():
    #                 args = []
    #                 for a in params:
    #                     args.append(data[a].astype(int))

    #                 output1 = c.run_func(file1_so,*args)["output"]
    #                 output2 = c.run_func(file2_so,*args)["output"]
             
    #                 df.loc[idx,cluster_name] = output2

    #                 if(output1 != output2):
    #                     print("Equivalance failed : Early terminated")
    #                     flag=False
    #                     break
    #                 print("\n")
    #             df.to_csv(testcases_file,index=False)
    #             return flag
    #         except Exception as e:
    #             print("Error in running test cases : ",e)
    #             return False

    def __build_runner_func(self) -> string:

        main_method = "\n\n int "+self.runner_function_name+"() \n{\n\t "
        scalar_arguments_dict = ut.get_scalar_argument_list()
        
        parameters=""
        for x in scalar_arguments_dict:
            type,name,value = scalar_arguments_dict[x]
            main_method = main_method + type + " " + name + ";\n"
            parameters = parameters + "," + name
        parameters = parameters[1:]

        function1_name = self.function_name+"1"
        function2_name = self.function_name+"2"
        main_method+= " if("+function1_name+"("+parameters+")"+" != "+function2_name+"("+parameters+")"+")"
        main_method+= "\nreturn 0;"
        main_method+= "\nreturn 1; \n }"
       
        return main_method


    def build_prog(self,solution1_path,solution2_path):
        cwd = os.getcwd()
        try:
            if not(isfile(solution1_path) and isfile(solution2_path)):
                print("Invalid File Path")
                return 

            solution1 = open(solution1_path,"r").read()
            solution2 = open(solution2_path,"r").read()
            
            solution1 = re.sub(self.function_name,self.function_name+"1",solution1,count=0)
            solution2 = re.sub(self.function_name,self.function_name+"2",solution2,count=0)

            runner_func = self.__build_runner_func()
            os.chdir(self.output_dir)

            if(self.runner_dir not in os.listdir()):
                os.mkdir(self.runner_dir)
            os.chdir(self.runner_dir)

            filename = os.path.basename(solution1_path)+"-"+os.path.basename(solution2_path)+".c"
            os.system("rm -f "+filename)
            temp_file = open(filename,"a+")
            temp_file.write("// File1 : "+os.path.basename(solution1_path)+" File2 : "+os.path.basename(solution2_path)+"\n")
            temp_file.write("#include<stdio.h>\n#include<stdlib.h>\n#include<assert.h>\n#include<string.h>\n\n")
            temp_file.write(solution1+"\n\n\n")
            temp_file.write(solution2+"\n\n\n")
            temp_file.write(runner_func)
            temp_file.close()

           
            filepath = os.path.abspath(filename)
            return filepath
        except Exception as e:
            print("Error in building prog : ",e)
        finally:
            os.chdir(cwd)

    def check_equivalance(self,solution1_path,solution2_path):
        
        try:
            df = pd.read_csv(self.testcases_file)
        except:
            print("Unable to read testcases file")
            return True
       
        c_obj = c()
        #prog = self.build_prog(solution1_path,solution2_path)
        #so_file = c_obj.build_so(prog)
        so1_file = c_obj.build_so(solution1_path)
        so2_file = c_obj.build_so(solution2_path)
        
        arg_list = ut.get_scalar_argument_list()


        for idx,data in df.iterrows():
            args = []     
            for idx in arg_list:
                var_type,var_name,var_val = arg_list[idx]
                args.append(data[var_name].astype(int))
            
            #output = c_obj.run_func(so_file,self.runner_function_name,*args)['output'] #c_obj.run_func(filepath=so_file,entry_point=self.runner_function_name)["output"]
            output1 = c_obj.run_func(so1_file,self.function_name,*args)['output']
            output2 = c_obj.run_func(so2_file,self.function_name,*args)['output']
            if(output1 != output2):
                print("Not equivalent")
                return False

        return True

        pass


if __name__ == '__main__':
        testcases_file = "/home/rt/autoval/klee-vol/testcases.csv"
        try:
            df = pd.read_csv(testcases_file)
        except:
            df = pd.DataFrame()
        arg_list = ut.get_scalar_argument_list()
        data=[]
        var_names = []
        
        for indx in arg_list:
            var_names.append(arg_list[indx][1])
        for i in range(0,500):
            data.append({'input_a':randint(0,1000)})
        print(data)
        df = df.append(pd.DataFrame(data))
        #print(data)
        df.drop_duplicates(subset=var_names,inplace=True, keep='first')
        df.to_csv(testcases_file,index=False)  