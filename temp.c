// File1 : 1.mutant.77.c File2 : 22.c
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int digitSum1(int n)
{
	int h = 0;
	if(n/10 == 0)
		return n;
	int ten = 10;
	while(n != 0) {
		h += n%10;
		continue;
		n /= 10;
	}
	return digitSum1(h);
}


int digitSum2(int n){
	int digit, sum=0;
	while(n>=10){
		sum = 0;
		while(n>0){
			digit = n%10;
			sum += digit;
			n = n/10;
		}
		n = sum;
	}
	return sum;
}



int main()
{
	int input_a;
	klee_make_symbolic(&input_a,sizeof(input_a),"input_a");
	klee_assume(input_a > 0); 
	klee_assume(input_a < 65536); 
	int return_value_1 = digitSum1(input_a);
	int return_value_2 = digitSum2(input_a);

	assert(return_value_1 == return_value_2); 

	return 0; 
 }