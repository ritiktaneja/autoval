
// #include <stdio.h>

int digitSum(int n)
{	

	// int sum = 0;
	// while(n>0){
	// 	sum += n%10;
	// 	n = n/10;
	// }

	// if(sum<=9){
	// 	return sum;
	// } else
	// return digitSum(sum);

	if(n ==0)
	return 0;

	if(n%9 ==0)
	return 9;

	return n%9;
	
}

// int main(){
// 	int n;
// 	scanf("%d",&n);
	
// 	printf("%d", digitSum(n));
// }

