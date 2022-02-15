#include <stdio.h>
int digitSum(int n)
{
    if (n == 0)
       return 0;
    if(n % 9 == 0) {
		return 9; 
	}else{
		return (n % 9);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int x = digitSum(n);
	printf("%d",x);
	return 0;
}