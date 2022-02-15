int digitSum(int n)
{
	//Write solution here
	int sum = 0;
	while (true) {
		while (n) {
			sum += (n % 10);
			n /= 10;
		}
		n = sum;
		if (n <= 9) break;
		else sum = 0;
	}
	return sum;
}
