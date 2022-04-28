import sys,os
scalar_args_fp = os.path.abspath("./config/scalar_args.txt")


def get_scalar_argument_list() -> dict:
        # Parse config file
        config_file = open(scalar_args_fp,"r")
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