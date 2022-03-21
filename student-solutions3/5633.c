#include <iostream>
using namespace std;
//-------------------------------------------------------------------|

int mod = 1e+9 + 7;	//	998244353
const int N = 2e+5 + 3;
//-------------------------------------------------------------------|

int digitSum(int n)
{
	if(n < 10)
		return n;

	int s = 0;
	while(n > 0)
	{
		s += n % 10;
		n = n / 10;
	}
	return digitSum(s);
}

int main()
{
	int n;
	// cin >> n;
	scanf("%d", n);

	int x = digitSum(n);

	printf("%d\n", x);
}