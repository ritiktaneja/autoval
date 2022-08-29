int digitSum(int n)
{
	//Write solution here
	int dig,sum;
	while(n>0){
		dig=n%10;
		sum=sum+dig;
		n=n/10;
	}
	int ans;
	if(sum>=10){
		ans=digitSum(sum);
	}
	else{
		return sum;
	}
	return ans;
}