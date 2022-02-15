
int digSum(int n)
{
	if(n < 10)
		return n;
 
	int s = 0;
	while(n > 0)
	{
		s += n % 10;
		n = n / 10;
	}
	return digSum(s);
}