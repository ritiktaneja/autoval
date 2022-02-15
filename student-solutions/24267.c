int digitSum(int n)
{
	int count = 0;
	int sum = 0;
	int m = 0;
	int temp = n;
	do
	{
    	temp /= 10;
    	++count;
  	} while (temp != 0);

	if(count == 1)
		return n;
	
	while(n>0)    
	{    
		m=n%10;    
		sum+=m;    
		n=n/10;    
	}

	return digitSum(sum);
}