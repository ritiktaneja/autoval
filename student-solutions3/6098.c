#include<stdio.h>
int digitSum(int n)
{
	 if(n<10)
	 	return n;
	 else
	 	return (digitSum(digitSum(n/10)+n%10));
}

// int main(){
// 	int n;
// 	scanf("%d",&n);
// 	int ans=digitSum(n);
// 	printf("%d \n",ans);
// 	return 0;
// }