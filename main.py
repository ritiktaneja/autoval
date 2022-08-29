

from ast import Pass
from datetime import date, datetime
from genericpath import isdir, isfile
import os,sys
import random
from cbmc import Cbmc,CbmcResponses
from config.bcolors import bcolors
import config.general as general
from klee import Klee,KleeResponses
from testcases_util import testcases_util
import util_tools as ut

import pandas as pd


from c import c

import re

from ctypes import *


'''
Script to separate students solutions into clusters based on behavourial equivalance.
'''


solutions_dir = os.path.join(os.getcwd(),general.solutions_dir)
cluster_dir = os.path.join(os.getcwd(),general.cluster_dir)
error_dir = os.path.join(os.getcwd(),general.error_dir)
testcases_file = os.path.join(os.getcwd(),general.testcases_file)
output_dir = os.path.abspath(general.output_dir)
solution_function_name = general.solution_function_name
solution_function_type = general.solution_function_type
klee_max_time = general.klee_max_time

random.seed(42)

mutants_dir = os.path.join(os.getcwd(),general.mutants_dir)

output_dir = "myoutput"
cluster_cnt = 1

def signal_handler(signum, frame):
    raise Exception("Timed out!")

def cleanMutants(mutants_dir):
    cwd = os.getcwd()
    mutants_list = os.listdir(mutants_dir)
    os.chdir(output_dir)
    toRemove = []
    for mutant_name in mutants_list:
        mutant = os.path.join(mutants_dir,mutant_name)
        os.system("clang -emit-llvm  -c "+mutant+" -o temp.bc 2> temp.txt")
        output = open("temp.txt","r").read()
        if len(re.findall(r": error:",output)) != 0 or not isfile("temp.bc"):
            toRemove.append(mutant)

    os.chdir(cwd)
    print(" Removing : ",toRemove)
    for mutant in toRemove:
        os.system("rm "+mutant)



def map_mutants(cluster_dir):

    print("Mapping mutants...")
    print("Current working directory : ",os.getcwd())
    cluster_dir = os.path.join(os.getcwd(),cluster_dir)
    result = dict()
   
    if isdir(mutants_dir) == False:
        print("Mutant directory not found")
        return
    
    cleanMutants(mutants_dir)

    if isdir(cluster_dir) == False:
        print("Cluster directory not found")
        return

    for mutant_name in os.listdir(mutants_dir):
        mutant = os.path.join(mutants_dir,mutant_name)
        print("\n\n\n\n",mutant)
        for curr_cluster_dir in os.listdir(cluster_dir):
            print("\n\nCluster : ",curr_cluster_dir)
            curr_sample = get_sample_from_cluster(os.path.join(cluster_dir,curr_cluster_dir))
            flag = True
        
            kleeResponse =  Klee(klee_flags=" -max-time=5s   -exit-on-error  ").check_equivalence(mutant,curr_sample)
            print(kleeResponse)
            if kleeResponse == KleeResponses.EQUIVALENT:
                print(bcolors.BOLD+bcolors.OKGREEN+"Mutant {} equivalent to cluster {}".format(mutant,curr_cluster_dir)+bcolors.ENDC) 
                result[mutant] = curr_cluster_dir
                flag = False
                break    

        if flag:
            print("Mutant Killed")
            result[mutant] = "Mutant Killed"      
        print(result)   


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
    solutions.sort()
    
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

    
    myKlee = Klee(klee_flags=" -max-time=10s ")  #klee runner init
    myCbmc = Cbmc(timeout=None, cbmc_flags=" --unwind 6 -z3 --unwinding-assertions")                                                                        
    myTestCasesUtil = testcases_util() # testcase runner init

    cnt = 0
    for solution in solutions:
        print("cnt = ",cnt)
        flag = True 
        solution_path = solutions_dir+"/"+solution
        print(bcolors.HEADER+bcolors.UNDERLINE+"\t\t\tsolution name :"+solution+bcolors.ENDC)
        
        if has_main_func(solution_path) or has_error(solution_path):
            print("Solution has main function")
            os.system("cp {} {}".format(solution_path,error_dir))
            continue

        print("\nChecking equivalance with generated clusters")
        

        for cluster in os.listdir(cluster_dir):
            
           
            print(bcolors.OKCYAN+"\n\t"+cluster+"\n "+bcolors.ENDC)
            current_cluster_dir = cluster_dir+"/"+cluster
            clustered_solution = get_sample_from_cluster(current_cluster_dir)
            
            tc_start = datetime.now()
            testcaseResponse =  myTestCasesUtil.check_equivalence(solution_path,clustered_solution)
            tc_end = datetime.now()
            if testcaseResponse == False:    
                print("Testcases Check failed")
                logTime(solution,cluster,os.path.basename(clustered_solution),(tc_end-tc_start).total_seconds(),0,0)
                continue
          
            # Then Running klee engine
            kleeResponse = myKlee.check_equivalence(solution1_path=solution_path,solution2_path=clustered_solution)
            print(kleeResponse)

            klee_end = datetime.now()
            
            if kleeResponse == KleeResponses.NOT_EQUIVALENT : #or kleeResponse == KleeResponses.TIME_LIMIT_EXCEEDED:
                logTime(solution,cluster,os.path.basename(clustered_solution),(tc_end-tc_start).total_seconds(),(klee_end-tc_end).total_seconds(),0)
                print("Klee check failed")
                continue
        
            cbmcResponse = myCbmc.check_equivalence(solution1_path=solution_path,solution2_path=clustered_solution)
            
            cbmc_end = datetime.now()
            logTime(solution,cluster,os.path.basename(clustered_solution),(tc_end-tc_start).total_seconds(),(klee_end-tc_end).total_seconds(),(cbmc_end-klee_end).total_seconds())

            if(cbmcResponse != CbmcResponses.SUCCESS):    
                print("Cbmc check failed")
                cnt+=1
                continue
            
            print(bcolors.BOLD+bcolors.OKGREEN+"Solution {} belongs to cluster {}".format(solution,cluster)+bcolors.ENDC) 
            os.system("cp {} {}".format(solution_path,current_cluster_dir))
            flag = False
            break    
            
        if flag:
            print(bcolors.BOLD+bcolors.OKCYAN+"Creating new cluster for solution {}".format(solution)+bcolors.ENDC)
            new_cluster_dir = cluster_dir+"/cluster"+str(cluster_cnt)+"/"
            os.system("mkdir {}".format(new_cluster_dir))
            os.system("cp {} {}".format(solution_path,new_cluster_dir))
            #run_test_cases(solution_path,solution_path,"cluster"+str(cluster_cnt))
            cluster_cnt+=1
        
        print("\n===================================================\n")

    tend = datetime.now()
    c = tend-tstart
    print("cnt : ",cnt)
    print("\n Number of Solutions : "+str(len(solutions))+"\n")
    print("\n Time Taken : "+str(c.seconds)+"\n")
    os.system('cd {} && find . -type f | cut -d/ -f2 | sort | uniq -c  '.format(cluster_dir))
                
       
def get_sample_from_cluster(current_cluster_dir):
    
    file_in_cluster=""
    for file in os.listdir(current_cluster_dir):
        if file.endswith(general.solution_file_extension):
            file_in_cluster = file
            break
    
    all_files = os.listdir(current_cluster_dir)
    file_in_cluster = all_files[random.randint(0,len(all_files)-1)]
    print("\nSample taken : ",file_in_cluster,"\n")
    
    
    clustered_solution = current_cluster_dir+"/"+file_in_cluster
    return clustered_solution

def has_main_func(soln_path):
    soln = open(soln_path,"r").read()
    return soln.find("main") !=-1

def logTime(sol,cluster,cluster_rep, tc_time,klee_time,cbmc_time):
    logs_filename = 'logs/digitsum-testcases(booted)-klee(unsound)-cbmc.csv'
    try:
        df= pd.read_csv(logs_filename)
    except:
        df = pd.DataFrame()
    
    dict = {}
    dict['solution'] = sol
    dict['cluster'] = cluster
    dict['cluster_rep'] = cluster_rep
    dict['testcases_time'] =  tc_time
    dict['klee_time'] = klee_time
    dict['cbmc_time'] = cbmc_time
    df = df.append(pd.DataFrame(dict,columns=dict.keys(),index=[0]))
    print(df)
    df.to_csv(logs_filename,index=False)    


def has_error(solution_path):
    try:
        c_obj = c()
        file1_so = c_obj.build_so(solution_path)

        #TODO remove this
        
        param_list=ut.get_scalar_argument_list()
        args = []
        for a in range(0,len(param_list)):
            args.append(1)
       
        output1 = c_obj.run_func(file1_so,general.solution_function_name,*args)
        if(output1['error'] == True):
            raise Exception("Run time error occured in precheck")   
        return False
    except Exception as e:
        print("Precheck Exception",e)
        return True

if __name__ == '__main__':
    if (len(sys.argv) > 2 and sys.argv[1] == "map_mutants"):
        map_mutants(sys.argv[2])
    else:
        create_clusters()




#d74631a0-350a-11e5-b84e-0242ac110011_2015-08-19_10_20_18.c