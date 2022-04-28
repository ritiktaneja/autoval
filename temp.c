// File1 : 24098.c File2 : 1448.c
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


int digitSum1(int n)
{
	//Write solution here
	if(n < 10){
	    return n;
	}
	
	else{
	    
	    if(n%10+ digitSum1(n/10) > 9){
	       return digitSum1(n%10 + digitSum1(n/10));
	    }
		
		else if(n%10+ digitSum1(n/10) <= 9){
	        return n%10 + digitSum1(n/10);
	    }
	}


}




int digitSum2(int n)
{
	if(n<=9){
		return n;
	}
	else{
		if(n%9==0){
			return 9;
		}
		return n%9;
	}
}


int nondet_int();

 int main()
{
	int input_a = nondet_int();

	 __CPROVER_assume(input_a>0);
	int return_value_1 = digitSum1(input_a);
	int return_value_2 = digitSum2(input_a);

	assert(return_value_1 == return_value_2); 

	return 0; 
 }