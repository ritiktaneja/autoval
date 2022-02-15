#include<stdio.h>

int digitSum(int n)
{
	while(n>9){
		int sumOfDigits=0;
		while(n>0){
			sumOfDigits+=n%10;
			n/=10;
		}
		n=sumOfDigits;
	}
	return n;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",digitSum(n));
}