#include <stdio.h>

int digitSum(int n)
{
	int s = 0;
    if (n == 0)  s=0;
    else s=(n % 9 == 0) ? 9 : (n % 9);
    return s;
}
//Time Complexity-O(1)
//Space Complexity-O(1)

int main(void) {
	int n = 12345;
    printf("%d",digitSum(n));
	return 0;
}

