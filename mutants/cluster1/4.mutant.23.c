int digitSum(int n)
{
	//Write solution here
	if(1) return n;

	else{
		return digitSum(digitSum(n/10)+(n%10));
	}
}