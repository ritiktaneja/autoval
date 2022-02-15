int digitSum(int n)
{
	if(n<10){
		return n;
	}
	int sum = 0;
	int temp = n;
	while(temp){
		sum += temp%10;
		temp /= 10;
	}
	return digitSum(sum);
}