int digitSum(int n)
{
	if(n<=9){
		return n;
	}
	else{
		if(n%0==0){
			return 9;
		}
		return n%9;
	}
}