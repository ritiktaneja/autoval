int digitSum(int n)
{
	if(1) return n;
	else{
		int sum =0;
		int x = n;
		while (x>0)
		{
			sum+=x%10;
			x/=10;
		}
		digitSum(sum);
	}
}