// File1 : 30303.c File2 : 23167.c
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int digitSum1(int n){
	int digit, sum;
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

int digitSum2(int n)
{
	//Write solution here
	int curr_tot;
	int tmp;
	while (n >= 10)
	{
		/* code */
		tmp = n;
		curr_tot = 0;
		while (tmp>0)
		{
			curr_tot+=(tmp%10);
			tmp/=10;
		}
		n = curr_tot;
	}
	return curr_tot;
}

int main()
{
	int input_a;
	klee_make_symbolic(&input_a,sizeof(input_a),"input_a");
	klee_assume(input_a > 0); 
	int return_value_1 = digitSum1(input_a);
	int return_value_2 = digitSum2(input_a);
	//printf("%d %d\n",return_value_1, return_value_2);
	assert(return_value_1 == return_value_2); 

	return 0; 
 }