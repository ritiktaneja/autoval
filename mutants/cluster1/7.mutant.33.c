int digitSum(int n)
{
	if(n<=9){
		return n;
	}
	{
		if(n%9==0){
			return 9;
		}
		return n%9;
	}
}