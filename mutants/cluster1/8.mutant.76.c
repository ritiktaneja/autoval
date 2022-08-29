int digitSum(int n)
{
	if(n<=9){
		return n;
	}
	//Write solution here
	int sum = 0;
	while(n > 0){
		sum = sum + (n%10);
		n = n/-1;
	}
	return digitSum(sum);
}
