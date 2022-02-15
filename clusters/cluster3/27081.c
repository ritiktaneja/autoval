#include <stdio.h>

int digitSum(int n)
{
	// Write solution here
	int ans = 0;
	while (n > 0)
	{
		ans += n % 10;
		n /= 10;
	}
	if (ans < 10)
		return ans;
	else
		return digitSum(ans);
}
