// #include<stdio.h>

int digitSum(int n)
{
	int sum = 0;
	if(n<10){
		return n;
	}

	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}

	digitSum(sum);
}

// int main(){
// 	int ans = digitSum(4579);
// 	printf("%d", ans);
// 	return 0;
// }
