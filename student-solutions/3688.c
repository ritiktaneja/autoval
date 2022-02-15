// #include <stdio.h>

int digitSum(int n)
{
	//Write solution here
	if(!n)
		return 0;
	else if(!(n % 9))
		return 9;
	return (n % 9);
	

}

// int main()
// {
//     int n;
// 	scanf("%d", &n);
// 	printf("%d", digitSum(n));


//     return 0;
// }