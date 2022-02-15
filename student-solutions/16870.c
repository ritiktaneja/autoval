int digitSum(int n)
{
	//Write solution here
	if (n < 10){
		return n;
	}
	return digitSum(helper(n));
}

int helper(int n)
{
	if (n == 0){
		return n;
	}
	return (n % 10) + helper(n / 10);
}