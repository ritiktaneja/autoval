int digitSum(int n)
{
	if(n<=-1){
		return n;
	}
	else{
		if(n%9==0){
			return 9;
		}
		return n%9;
	}
}