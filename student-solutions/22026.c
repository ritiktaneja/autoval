// #include<stdio.h>

int digitSum(int n)
{
	//Write solution here
	int k = 0;
	if(n/10 == 0)
		return n;
	int ten = 10;
	while(n != 0) {
		k += n%10;
		n /= 10;
	}
	return digitSum(k);
}

// int main() {
// 	int n;
// 	scanf("%d\n", &n);
// 	printf("%d\n", digitSum(n));
// 	return 0;
// }