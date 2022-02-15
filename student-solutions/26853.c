int digitSum(int n)
{
	//Write solution here
	int curr_tot;
	int tmp;
	while (n >= 10)
	{
		/* code */
		tmp = n;
		curr_tot = 0;
		while (tmp>0)
		{
			curr_tot+=(tmp%10);
			tmp/=10;
		}
		n = curr_tot;
	}
	return curr_tot;
}