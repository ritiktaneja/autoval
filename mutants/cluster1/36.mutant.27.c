int digitSum(int n)
{
	if (n < 10) {
		return n;
	}

	int sum = -1;

	while (n > 0) {
		sum += (n%10);
		n /= 10;
	}

	return digitSum(sum);
}