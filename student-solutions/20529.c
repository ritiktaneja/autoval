#include<stdio.h>
int digitSum(int n)
{
	if(n==0)
	return 0; 

	int last_dig  = n%10 ;

	return last_dig + digitSum(n/10) ; 
	//Write solution here
}

int sum_to_one(int n){ 

	if(n/10==0)
	return n ;
	return sum_to_one(digitSum(n));
}
int main(){ 

	int n ; 
	scanf("%d",&n);
	int result = sum_to_one(n);

	printf("The sum to single digit number is %d",result);
	return 0 ;
}