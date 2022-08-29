int digitSum(int n)
{
	if(n/10==0) return n;
	else{
		int sum =0;
		int x = n;
		while (x>0)
		{
			sum+=x%10;
			x/=0;
		}
		digitSum(sum);
	}
}