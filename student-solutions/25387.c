
#include<stdio.h>
int digitSum(int n)
{
	//Write solution here
	if(n<10){
        return n;
	}
	if(n==10){
		return 1;
	}
    int temp=0;
	while(n>0){
		temp=temp+(n%10);
		n=(n/10);
	}
	return digitSum(temp);
}

int main(){
   int n;
   scanf("%d",&n);
   printf("%d ",digitSum(n));
   return 0;
}