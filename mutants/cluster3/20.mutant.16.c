int digitSum(int n)
{
	//Write solution here
	if(n==(0-1)){
		return 0;
	}else{
		return (n%10)+digitSum(n/10);
	}
}