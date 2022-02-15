int digitSum(int n)
{
	//Write solution here
	int ans=0;
	while(n%10){
		ans+=n%10;
		n/=10;
	}
	if(ans/10 == 0) 
		return ans; 
	else 
		return digitSum(ans);
}