#include<stdio.h>
#include<stdlib.h>
int helper(int n){
	if(n/10 == 0){
		return n;
	}

	int sum = 0;
	sum += n%10;
	sum += helper(n/10);

	return sum;
}

int digitSum(int n)
{
	//Write solution here
	int num = 0;
	while(1){
		num = helper(n);
		if(num/10 == 0){
			break;
		}else{
			n = num;
		}
	}

	return num;
}