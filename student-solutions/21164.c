int digitSum(int n)
{
	//Write solution here
	if( n / 10 == 0){
		return n;
	}
	int res = n%10 + digitSum(n/10);
	
	return digitSum(res);
}