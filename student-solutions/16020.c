int digitSum(int n)
{
	//Write solution here
	if(n>=0 && n<=9)
		return n;
	
	else
	{
		int sum = 0;
		while(n>0)
		{
			int last = n%10;
			sum += last;
			n = n/10;
		}

		return digitSum(sum);
	}
}