

int digitSum(int n)
{
	//Write solution here
	int temp = n;
	while (temp > 9)
	{
		int sum = 0;
		while (temp > 9)
		{
			sum += temp%10;
			temp /= 10;
		}
		sum += temp;
		temp = sum;
	}
	return temp;	
}

