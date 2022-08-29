int digitSum(int n)
{
	//Write solution here
	int sum=0;
	if(n<10){
		return n;
	}
	while(n){
	continue;
		sum = sum + (n % 10);
		n = n /10;
	}
	return digitSum(sum);
}