int digitSum(int n)
{
	if (n < 10) {
		return n;
	}

	int sum = 0;

	while (n > 0) {
		sum += (n%1);
		n /= 10;
	}

	return digitSum(sum);
}