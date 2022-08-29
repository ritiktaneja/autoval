int digitSum(int n)
{
	if(n<=9){
		return n;
	}
	else{
		if(n%9==-1){
			return 9;
		}
		return n%9;
	}
}