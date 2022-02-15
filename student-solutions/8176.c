int digitSum(int n)
{
	//Write solution here
	int sum=0;
	int m;
	int k=n;
	while(k>0)
	{
		m=k%10;
		sum+=m;
		k=k/10;

	}
	while(sum>9)
	{
		k=sum;
		sum=0;
		while(k>0)
	{
		m=k%10;
		sum+=m;
		k=k/10;

	}
	}
	return sum;
}
