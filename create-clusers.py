from distutils.log import error
from genericpath import isdir
import os
import sys
from RESPONSE_CODES import Response
from config.bcolors import bcolors
import config.general as general,klee_equivalence
'''
Script to separate students solutions into clusters based on behavourial equivalance.
'''


solutions_dir = os.getcwd()+general.solutions_dir
cluster_dir = os.getcwd()+general.cluster_dir
error_dir = os.getcwd()+general.error_dir


def create_clusters():
    print("\n\n"+bcolors.HEADER+"Create clusters script init"+bcolors.ENDC)
    print("Current working directory : ",os.getcwd())
    if  isdir(solutions_dir) == False :
        print("Solutions Directory Not Found")
        return
    
    solutions= [f for f in os.listdir(solutions_dir) if f.endswith('.c')]
    
    if len(solutions) == 0:
        print(bcolors.WARNING+"No C program found in solutions directory"+bcolors.ENDC)
        return
    if isdir(cluster_dir) == True:
        print(bcolors.WARNING+"Previous clustering found. Deleting Previous clustering"+bcolors.ENDC)
        os.system('rm -r {}'.format(cluster_dir))
    
    if isdir(error_dir) == True:
        os.system('rm -r {}'.format(error_dir))
    
    os.system('mkdir {}'.format(cluster_dir))
    os.system('mkdir {}'.format(error_dir)) 

    print("\n====================================================================\n")
    for solution in solutions:
        flag = True 
        cluster_cnt = 0
        solution_path = solutions_dir+"/"+solution
        print(bcolors.HEADER+bcolors.UNDERLINE+"solution name :"+solution+bcolors.ENDC)
        for cluster in os.listdir(cluster_dir):
            current_cluster_dir = cluster_dir+"/"+cluster

            if(isdir(current_cluster_dir)):
                cluster_cnt+=1
                file_in_cluster=""
                
                for file in os.listdir(current_cluster_dir):
                  if file.endswith(general.solution_file_extension):
                    file_in_cluster = file
                    break
                
                if file_in_cluster == "":
                    print("No file found in cluster dir",cluster)
                    print("Deleting cluster dir ",cluster_dir)
                    os.system("rm -r {}",current_cluster_dir)
                    continue
                
                #Checking equivalence
                print("Checking current soln with solution in cluster "+cluster+bcolors.ENDC)
                clustered_solution = current_cluster_dir+"/"+file_in_cluster
                myResp = klee_equivalence.check_equivalance(solution_path,clustered_solution)
                
                if(myResp == Response.EQUIVALENT):
                    print(bcolors.BOLD+bcolors.OKGREEN+"Solution {} belongs to cluster {}".format(solution,cluster)+bcolors.ENDC) 
                    os.system("cp {} {}".format(solution_path,current_cluster_dir))
                    flag = False
                    break                
                elif myResp == Response.COMPILE_TIME_ERROR or myResp == Response.TIME_LIMIT_EXCEEDED:
                    print(bcolors.BOLD+bcolors.FAIL+"Compile Time Error or Run Time Error Occurred"+bcolors.ENDC)
                    os.system("cp {} {}".format(solution_path,error_dir))
                    flag = False
                    break

        if flag:
            print(bcolors.BOLD+bcolors.OKCYAN+"Creating new cluster for solution {}".format(solution)+bcolors.ENDC)
            new_cluster_dir = cluster_dir+"/cluster"+str(cluster_cnt)+"/"
            os.system("mkdir {}".format(new_cluster_dir))
            os.system("cp {} {}".format(solution_path,new_cluster_dir))
        
        print("\n===================================================\n")

    os.system('cd {} && find . -type f | cut -d "/" -f 2 | sort | uniq -c | sort -n'.format(cluster_dir))
                


    



    
    






if __name__ == '__main__':
    create_clusters()
