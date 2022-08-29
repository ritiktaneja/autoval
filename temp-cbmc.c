// File1 : 39.c File2 : 44.c
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int digitSum1(int n)
{
	if(n < 10)
	{
		return n;
	}

	else
	{
		int a = 0, sum = 0;

		while(n > 0)
		{
			a = (n % 10);
			sum += a;
			n = (n / 10);
		}

		return digitSum1(sum);
	}

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
		return digitSum2(sum);
	}
}


int nondet_int();

 int main()
{
	int input_a = nondet_int();

	 __CPROVER_assume(input_a>0); 
	 __CPROVER_assume(input_a<65536);
	int return_value_1 = digitSum1(input_a);
	int return_value_2 = digitSum2(input_a);

	assert(return_value_1 == return_value_2); 

	return 0; 
 }