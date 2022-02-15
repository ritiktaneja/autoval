int digitSum(int n)
{
	//Write solution here
	if(n/10 == 0){
		return n;
	}
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}

	return digitSum(sum);
}