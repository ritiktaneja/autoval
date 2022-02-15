#include <stdio.h>
int digitSum(int n)
{
	//Write solution here
	if(n==0){
		return 0;
	}
	if(n%9==0){
		return 9;
	}
	return n%9;
}

/* for running testcases
int main(){
	int n;
	scanf("%d",&n);
	int x = digitSum(n);
	printf("%d",x);
	return 0;
}*/