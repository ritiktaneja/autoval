int digitSum(int n)
{
	//Write solution here
	int sum;
	while(n>=10){
		sum=0;
		while(n>0){
			sum+=(n%10);
			n/=10;
		}
		n=sum;
	}
	return sum;
}