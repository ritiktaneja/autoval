int digitSum(int n)
{
	//Write solution here
	int digit_sum = 0;
	while(n > 0)
	{
		digit_sum = digit_sum + (n % 10);
		n = n / 10;
	}

	if(digit_sum > 9)
		digit_sum = digitSum(digit_sum);

	return digit_sum;
}