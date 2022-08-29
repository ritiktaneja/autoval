from ast import Pass
from genericpath import isdir, isfile
import re
import sys
from typing import Dict
from config import general
import os
import pandas as pd
from klee import Klee, KleeResponses
class MutantUtil:

    def __init__(self):
        self.mutants_dir = os.path.abspath(general.mutants_dir)
        self.output_dir =  os.path.abspath(general.output_dir)
        self.MAX_TLE_CNT = 10

    def cleanMutants(self,mutants_dir):
        cwd = os.getcwd()
        mutants_list = os.listdir(mutants_dir)
        os.chdir(self.output_dir)
        toRemove = []
        for mutant_name in mutants_list:
            print("compiling ",mutant_name)
            mutant = os.path.join(mutants_dir,mutant_name)
            os.system("clang -emit-llvm  -c "+mutant+" -o temp.bc 2> temp.txt")
            output = open("temp.txt","r").read()
            
            if len(re.findall(r": error:",output)) != 0 or not isfile("temp.bc"):
                toRemove.append(mutant)

        os.chdir(cwd)
        print(" Removing : ",toRemove)
        for mutant in toRemove:
            os.system("rm "+mutant)


    def create_mutants_for_cluster(self,cluster_dir):
        cwd = os.getcwd()
        if (isdir(self.mutants_dir) == False):
            os.mkdir(self.mutants_dir)
        cluster_name = os.path.basename(cluster_dir)

        output_dir = os.path.abspath(os.path.join(self.mutants_dir,cluster_name))
        if (isdir(output_dir)):
            print("Mutants already exist")
            return
        os.mkdir(output_dir)
        for solution in os.listdir(cluster_dir):   
        
            path = os.path.join(cluster_dir,solution)
            print(path,"\n\n")
            os.system("mutate "+path+ " --mutantDir "+output_dir)
        self.cleanMutants(output_dir)
        os.chdir(cwd)
    
    def create_mutants_for_all_clusters(self,clusters_dir):
        for cluster in os.listdir(clusters_dir):
            self.create_mutants_for_cluster(os.path.abspath(os.path.join(clusters_dir,cluster)))
    

    # def map_mutants(self,cluster_dir):

    #     print("Mapping mutants...")
    #     print("Current working directory : ",os.getcwd())
    #     cluster_dir = os.path.join(os.getcwd(),cluster_dir)
    #     result = dict()
    #     mutants_dir = self.mutants_dir
    #     if isdir(mutants_dir) == False:
    #         print("Mutant directory not found")
    #         return

    #     if isdir(cluster_dir) == False:
    #         print("Cluster directory not found")
    #         return

    #     for mutant_name in os.listdir(mutants_dir):
    #         mutant = os.path.join(mutants_dir,mutant_name)
    #         print("\n\n\n\n",mutant)
    #         for curr_cluster_dir in os.listdir(cluster_dir):
    #             print("\n\nCluster : ",curr_cluster_dir)
    #             curr_sample = get_sample_from_cluster(os.path.join(cluster_dir,curr_cluster_dir))
    #             flag = True
            
    #             kleeResponse =  Klee(klee_flags=" -max-time=5s   -exit-on-error  ").check_equivalence(mutant,curr_sample)
    #             print(kleeResponse)
    #             if kleeResponse == KleeResponses.EQUIVALENT:
    #                 print(bcolors.BOLD+bcolors.OKGREEN+"Mutant {} equivalent to cluster {}".format(mutant,curr_cluster_dir)+bcolors.ENDC) 
    #                 result[mutant] = curr_cluster_dir
    #                 flag = False
    #                 break    

    #         if flag:
    #             print("Mutant Killed")
    #             result[mutant] = "Mutant Killed"      
    #         print(result)   


    def map_clusters(self,clusters_dir):

        if not isdir("mutants_logs"):
            os.mkdir("mutants_logs")

        result = dict()
        logger = dict()
        clusters_dir_list = os.listdir(clusters_dir)
        for cluster_dir1 in clusters_dir_list:
            result[cluster_dir1] = dict()
            logger[cluster_dir1] = dict()
            for cluster_dir2 in clusters_dir_list:
                if cluster_dir1 != cluster_dir2:
                    result[cluster_dir1][cluster_dir2] = float('inf') 
                else :
                    result[cluster_dir1][cluster_dir2] = 0

        # for i in range(0,len(clusters_dir_list)):
        for j in range(0,len(clusters_dir_list)): 
            cluster1_name = "cluster1" # clusters_dir_list[i]
            cluster2_name = clusters_dir_list[j]
            
            if(cluster2_name == cluster1_name):
                continue
            cluster1_path = os.path.join(clusters_dir,cluster1_name)
            cluster2_path = os.path.join(clusters_dir,cluster2_name)
            
            mutants1_path = os.path.join(self.mutants_dir,cluster1_name)
            mutants2_path = os.path.join(self.mutants_dir,cluster2_name)
            
            print(cluster1_path)
            print(cluster2_path)
            print(mutants1_path)
            print(mutants2_path)

            ## mutants from cluster 1 with solutions from cluster 2:    
            if self.check_equivalence(mutants1_path,cluster2_path,logger):
                result[cluster1_name][cluster2_name] = 1
                result[cluster2_name][cluster1_name] = 1

            # ## mutants from cluster 2 with solutions from cluster 1:
            # elif self.check_equivalence(cluster1_path,mutants2_path,logger):
            #     result[cluster1_name][cluster2_name] = 1
            #     result[cluster2_name][cluster1_name] = 1

            # ## mutants from cluster 1 with mutants from cluster 2
            # elif self.check_equivalence(mutants1_path,mutants2_path,logger):
            #     result[cluster1_name][cluster2_name] = 2
            #     result[cluster2_name][cluster1_name] = 2   

            df = pd.DataFrame(result)
            print(df)
            df.to_csv("mutants_logs/mutants_matching5.csv")
            df2 = pd.DataFrame(logger)
            print(df2)
            df2.to_csv("mutants_logs/mutants_matching_logs5.csv")
            Pass

    def check_equivalence(self,dir1_path,dir2_path,logger):
        print("\n\n \t\t Comparing "+dir1_path+" and "+dir2_path)
        myKlee = Klee(klee_flags=" -max-time=5s -exit-on-error ")
        tle_cnt = 0
        for sol2 in os.listdir(dir2_path):
            for sol1 in os.listdir(dir1_path):
                if (sol1[0:2] != "1."):
                    continue
                print("\nComparing {} ({}) and {} ({}) ".format(sol1,dir1_path,sol2,dir2_path))
                sol1_path = os.path.join(dir1_path,sol1)
                sol2_path = os.path.join(dir2_path,sol2)
                
                kleeResponse = myKlee.check_equivalence(sol1_path,sol2_path)
                print(kleeResponse)
                if(kleeResponse == KleeResponses.EQUIVALENT):
                    logger[os.path.basename(dir1_path)][os.path.basename(dir2_path)] = sol1+" "+sol2
                    logger[os.path.basename(dir2_path)][os.path.basename(dir1_path)] = sol1+" "+sol2
                    return True
                # elif kleeResponse == KleeResponses.NOT_EQUIVALENT:
                #     return False
                # else:
                #     tle_cnt+=1
                #     if tle_cnt > self.MAX_TLE_CNT:
                #         return False

        
        Pass

if __name__ == "__main__":
    util = MutantUtil()
    if(sys.argv[1] == "createMutants"):
        util.create_mutants_for_cluster(os.path.abspath(sys.argv[2]))
    elif(sys.argv[1] == "createMutantsForAll"):
        util.create_mutants_for_all_clusters(os.path.abspath(sys.argv[2]))
    elif(sys.argv[1] == "mapClusters"):
        util.map_clusters(os.path.abspath(sys.argv[2]))
    else:
        print("Invalid Argument")



