int digitSum(int n)
{
	if(n<10) 
    {
        return n;
    }
	int sol=0;

	while(n>0)
    {

		sol=sol+(n%10);
		n=n/10;
	}
	return digitSum(sol);

}