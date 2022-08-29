int digitSum(int n)
{
	//Write solution here
	if(n<10) return n;

	else{
		return digitSum(digitSum(n/(10-1))+(n%10));
	}
}