int digitSum(int n)
{
	//Write solution here
	if(n<10)
	{
		return n;
	}
	else
	{
		int temp = n;
		int sum=0;
		while(temp>0)
		{
			int dig = temp%10;
			sum+=dig;
			temp = temp/10;
		}

		return digitSum(sum);
	}
}
