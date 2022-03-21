// File1 : 30303.c File2 : 23167.c
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int digitSum1(int n)
{
	if(n<10){
		return n;
	}
	int temp=0;
	while(n>0){
		temp+=(n%10);
		n/=10;
	}
	return digitSum1(temp);
}


int digitSum2(int n)
{
	if(n/10==0) return n;
	else{
		int sum =0;
		int x = n;
		while (x>0)
		{
			sum+=x%10;
			x/=10;
		}
		digitSum2(sum);
	}
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