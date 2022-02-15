int digitSum(int n)
{
	//Write solution here
	if(n >= 0 && n < 10)
		return n;
	else
	{
		int temp = n % 10 + digitSum(n/10);
		if(temp >= 10)
			return digitSum(temp);
		else
			return temp;
	}
}
