#include <stdlib.h>

int digitSum(int x) {
	if (x / 10 == 0)return x;
	int ans = 0;
	while (x > 0) {
		ans += (x % 10);
		x /= 10;
	}
	return rec(ans);
}