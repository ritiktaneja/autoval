#include <stdio.h>

// Given a positive integer N, find the sum of its digits recursively until we get a single digit number and return the number.
int digitSum(int n)
{
	//Write solution here
    if (n == 0)
       return 0;
    return (n % 9 == 0) ? 9 : (n % 9);
}

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%d", digitSum(n));
//     return 0;
// }

