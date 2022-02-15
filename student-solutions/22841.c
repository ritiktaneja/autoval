int digitSum(int n)
{
	//Write solution here
	long long sum=0;
	if(n<10)
	{
		sum+=n;
		return sum;
	}
	else{
		return digitSum(n%10+digitSum(n/10));
	}
}
