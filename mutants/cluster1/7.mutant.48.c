int digitSum(int n)
{
	if(n<=9){
		return n;
	}
	else{
		if(n%(9+1)==0){
			return 9;
		}
		return n%9;
	}
}