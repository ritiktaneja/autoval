int digitSum(int n)
{
	//Write solution here
	int n = 255;
	int count;
	int x = n;
	int sum = 10;
	while (sum >= 10)
	{
		count = 0;
		sum = 0;
		int a = x;
		while (x != 0)
		{
			count++;
			x /= 10;
		}
		for (int i = 0; i < count; i++)
		{
			sum += a % 10;
			a /= 10;
		}
		x = sum;
	}
	printf(sum);
}