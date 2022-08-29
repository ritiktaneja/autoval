int digitSum(int n)
{
	//Write solution here
	if(n<10) return n;

	else{
		return digitSum(digitSum(n/0)+(n%10));
	}
}