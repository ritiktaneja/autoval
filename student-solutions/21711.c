

int digSum(int n)
{
	//Write solution here
	int sum = 0;
	while(n>0)
	{
	    if(n<10)
	    {
	        return n;
	    }
		if(n==0)
		{
			n = sum;
			sum = 0;
		}
		sum+=n%10;
		n /= 10;
	}

	return digSum(sum);
}

