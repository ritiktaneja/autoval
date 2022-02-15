int digitSum(int n)
{
	if(n>=0 && n<10)
		return n;
	else
		return digitSum(n/10)+n%10;

}