
import string
import uuid
import function_parser

def equivalence_main(function_type,function1_name,function2_name)-> string:
    main_method = "int main()\n{\n\t"

    scalar_arguments_dict = function_parser.get_scalar_argument_list()
    #print("Scalar Arguments : ",scalar_arguments_dict)


    parameters=""

    for x in scalar_arguments_dict:
        type,name,value = scalar_arguments_dict[x]
        if value.isnumeric():
            main_method = main_method + type + " " + name + " = " + value + ";\n\n\t"
        else:
            main_method = main_method + type + " " + name + ";\n\tklee_make_symbolic(&" + name + ",sizeof(" + name + "),\"" + name + "\");\n\n\t"
        
        
        parameters = parameters + "," + name
    
    parameters = parameters[1:]
    
   # print(parameters)
    main_method = main_method + function_type + " return_value_1 = " + function1_name + "(" + parameters + ");\n\t"
    main_method = main_method + function_type + " return_value_2 = " + function2_name + "(" + parameters + ");\n\n\t"

    main_method = main_method + "assert(return_value_1 == return_value_2); \n\n"
    main_method = main_method + "\treturn 0; \n }"
    
    return main_method


if __name__ == "__main__":
    equivalence_main("int","func1","func2")