#include<stdio.h>

int digitSum(int n)
{
	if(n == 0){
		return 0;
	}
	else{
		int r = n % 9;
		if(r == 0){
			return 9;
		}
		else{
			return r;
		}
	}
}

int main(){

	int n = 991;
	int ans = digitSum(n);
	printf("%d", ans);

	return 0;
}