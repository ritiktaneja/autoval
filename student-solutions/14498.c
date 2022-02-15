int digitSum(int n)
{
	//Write solution here
	while(n/10!=0){
		int sum = 0;
		while(n){
			sum+=(n%10);
			n/=10;
		}
		n=sum;
	}
	return n;
}
