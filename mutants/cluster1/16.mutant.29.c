int digitSum(int n)
{
	//Write solution here
	int sum=0;
	if(0){
		return n;
	}
	while(n){
		sum = sum + (n % 10);
		n = n /10;
	}
	return digitSum(sum);
}