// File1 : 604.c File2 : 3465.c
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int digitSum1(int n)
{
	if (n <= 9)
		return n;
	int sum = 0;
	while (n > 0)
	{
		sum = sum + (n % 10);
		n = n / 10;
	}
	return digitSum1(sum);
}



int digitSum2(int n)
{
	//Write solution here
	if (!n)return 0;
    return (!(n % 9)) ? 9 : (n % 9);
}


int main()
{
	int input_a;
	klee_make_symbolic(&input_a,sizeof(input_a),"input_a");
	klee_assume(input_a > 0); 
	int return_value_1 = digitSum1(input_a);
	int return_value_2 = digitSum2(input_a);

	assert(return_value_1 == return_value_2); 

	return 0; 
 }