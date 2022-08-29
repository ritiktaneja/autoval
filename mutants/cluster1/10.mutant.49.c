
int digitSum(int n)
{
	if(n<=9){
		return n;
	}	
	int sum=0;
	if(n>0){
		sum+=n%10;
		n=n/10;
	}
	return digitSum(sum);
}