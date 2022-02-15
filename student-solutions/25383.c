int digitSum(int n)
{
	//Write solution here
	if(n==0)
		return 0;
	if(n<10)
		return n;
	while(n>=10)
	{
		int sum=0;
		while(n>0)
		{
			sum+=n%10;
			n/=10;
		}
		n=sum;
	}
}
