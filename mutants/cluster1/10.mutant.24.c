
int digitSum(int n)
{
	if(1){
		return n;
	}	
	int sum=0;
	while(n>0){
		sum+=n%10;
		n=n/10;
	}
	return digitSum(sum);
}