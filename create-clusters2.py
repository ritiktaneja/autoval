
from cmath import nan
from datetime import datetime
from genericpath import isdir
import os
from random import randint, random
from re import I
import re
from sys import flags

from typing import Dict, Set

from config.bcolors import bcolors
import config.general as general
from klee import Klee
from equivalance_checker_util import equivalance_checker_util
import pandas as pd
from c import c

from ctypes import *

'''
Script to separate students solutions into clusters based on behavourial equivalance.
'''


solutions_dir = os.getcwd()+general.solutions_dir
cluster_dir = os.getcwd()+general.cluster_dir
error_dir = os.getcwd()+general.error_dir
testcases_file = os.getcwd()+general.testcases_file
output_dir = "myoutput"
cluster_cnt = 1



def create_clusters():
    global cluster_cnt  
    
    tstart = datetime.now()

    print("\n\n"+bcolors.HEADER+"Create clusters script init"+bcolors.ENDC)
    print("Current working directory : ",os.getcwd())
    if  isdir(solutions_dir) == False :
        print("Solutions Directory Not Found")
        return

    os.system("rm -r "+output_dir)
    #os.system("rm "+testcases_file)
    #os.system("touch "+testcases_file)
   
    if isdir(output_dir) == False:
        os.mkdir(output_dir)
    
    solutions= [f for f in os.listdir(solutions_dir) if f.endswith('.c')]
    
    if len(solutions) == 0:
        print(bcolors.WARNING+"No C program found in solutions directory"+bcolors.ENDC)
        return
    if isdir(cluster_dir) == True:
        print(bcolors.WARNING+"Previous clustering found. Deleting Previous clustering"+bcolors.ENDC)
        os.system('rm -r {}'.format(cluster_dir))
    
    if isdir(error_dir) == True:
        os.system('rm -r {}'.format(error_dir))
    
    if isdir(output_dir):
        os.system("rm -r "+output_dir)

    
    os.system('mkdir {}'.format(cluster_dir))
    os.system('mkdir {}'.format(error_dir)) 
    os.system('mkdir {}'.format(output_dir)) 

    print("\n====================================================================\n")


    for solution in solutions:
       
        flag = True 
        solution_path = solutions_dir+"/"+solution
        print(bcolors.HEADER+bcolors.UNDERLINE+"\t\t\tsolution name :"+solution+bcolors.ENDC)
        
        if has_main_func(solution_path):
            print("Solution has main function")
            os.system("cp {} {}".format(solution_path,error_dir))
            continue

        print("\nChecking equivalance with generated clusters")

        for cluster in os.listdir(cluster_dir):
            
            print(bcolors.OKCYAN+"\n\t"+cluster+"\n "+bcolors.ENDC)
            current_cluster_dir = cluster_dir+"/"+cluster
            clustered_solution = get_sample_from_cluster(current_cluster_dir)

            # print("\t\t Checking with sample from  ",cluster,bcolors.ENDC)

            if run_test_cases(solution_path,clustered_solution,cluster) == False:
                continue

            print("Testcases passed")

            testcases = klee_runner(solution_path,clustered_solution)
           
            if testcases== None or len(testcases) == 0:
                print(bcolors.BOLD+bcolors.OKGREEN+"Solution {} belongs to cluster {}".format(solution,cluster)+bcolors.ENDC) 
                os.system("cp {} {}".format(solution_path,current_cluster_dir))
                flag = False
                break    
            else:
                print("Equivalance check failed"+bcolors.ENDC)
                push_testcases(testcases)  #Update global testcases file
            
        if flag:
            print(bcolors.BOLD+bcolors.OKCYAN+"Creating new cluster for solution {}".format(solution)+bcolors.ENDC)
            new_cluster_dir = cluster_dir+"/cluster"+str(cluster_cnt)+"/"
            cluster_cnt+=1
            os.system("mkdir {}".format(new_cluster_dir))
            os.system("cp {} {}".format(solution_path,new_cluster_dir))
        
        print("\n===================================================\n")

    tend = datetime.now()
    c = tend-tstart
    print("\n Number of Solutions : "+str(len(solutions))+"\n")
    print("\n Time Taken : "+str(c.seconds)+"\n")
    os.system('cd {} && find . -type f | cut -d "/" -f 2 | sort | uniq -c | sort -n'.format(cluster_dir))
                

def klee_runner(solution_path,clustered_solution):
            filename = "temp.c"
            obj = equivalance_checker_util()
            obj.build_program(clustered_solution,solution_path,filename=filename)
        
            res = []
            myKlee = Klee()
            myKlee.run(filename,output_dir)
            res = myKlee.get_result_object(output_dir)
            return res

def push_testcases(testcases):
    print("\nPushing testcases to global file : {} \n".format(testcases))
    # testcases = [[testcase['objects'] for testcase in testcases][0]]
    data=[]

    for testcase in testcases:
        data.append(testcase['objects'])
    

    obj = equivalance_checker_util()
    args_list=obj.get_scalar_argument_list()
    args = []
    for key,indx in enumerate(args_list):
          args.append(args_list[indx][1])

    try:
        df = pd.read_csv(testcases_file)
    except:
        df = pd.DataFrame()
    
    df = df.append(pd.DataFrame(data))
  
    df.drop_duplicates(subset=args,inplace=True, keep='first')
    df.to_csv(testcases_file,index=False)  
    

def run_test_cases(filepath1,clustered_solution,cluster_name):
    # try:
        
            try:
                df = pd.read_csv(testcases_file)
            except:
                df = pd.DataFrame()
            flag = True

            obj = equivalance_checker_util()
            param_list=obj.get_scalar_argument_list()
            params = []

            for key,indx in enumerate(param_list):
                params.append(param_list[indx][1])

            file1_so = c.build_so(filepath1)
            file2_so = c.build_so(clustered_solution)

            for idx,data in df.iterrows():
                args = []
                for a in params:
                    args.append(data[a].astype(int))

                output1 = c.run_func(file1_so,*args)["output"]

                # output2 = None if cluster_name not in data.index else data[cluster_name]
                # if(output2 == None or output2 == nan):
                
                output2 = c.run_func(file2_so,*args)["output"]

                df.loc[idx,cluster_name] = output2

                if(output1 != output2):
                    flag=False
                    break
            
            df.to_csv(testcases_file,index=False)

            return flag
       
    # except e:
    #     print("error running testcases")
    #     return []

def get_sample_from_cluster(current_cluster_dir):
    
    file_in_cluster=""
    for file in os.listdir(current_cluster_dir):
        if file.endswith(general.solution_file_extension):
            file_in_cluster = file
            break
    
    all_files = os.listdir(current_cluster_dir)
    file_in_cluster = all_files[randint(0,len(all_files)-1)]
    print("\nSample taken : ",file_in_cluster,"\n")
    
    
    clustered_solution = current_cluster_dir+"/"+file_in_cluster
    return clustered_solution

def has_main_func(soln_path):
    soln = open(soln_path,"r").read()
    return soln.find("main") !=-1


if __name__ == '__main__':
    #args = [(5),(0)]
    #c.run_func(solutions_dir+"/../clusters/cluster1/5.c",*args)
    create_clusters()
