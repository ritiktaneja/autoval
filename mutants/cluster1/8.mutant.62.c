int digitSum(int n)
{
	if(n<=9){
		return n;
	}
	//Write solution here
	int sum = 0;
	while(n > 0){
		sum = sum + (n%0);
		n = n/10;
	}
	return digitSum(sum);
}
