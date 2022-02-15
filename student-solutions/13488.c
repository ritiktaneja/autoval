
int digitSum(int n)
{
	//Write solution here=
	if(n<=9)
	{
		return n;
	}

	int temp = n;
	int sum = 0;
	while(temp > 0)
	{
		sum+=temp%10;
		temp = temp/10;
	}
	return digitSum(sum);
}


