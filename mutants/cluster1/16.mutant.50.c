int digitSum(int n)
{
	//Write solution here
	int sum=0;
	if(n<10){
		return n;
	}
	while(n){
		sum = sum + (n % 1);
		n = n /10;
	}
	return digitSum(sum);
}