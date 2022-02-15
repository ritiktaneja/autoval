int digitSum(int n)
{
	int sum = 0;
	while(sum>9||n>0){
		if(n == 0){
			n = sum;
			sum = 0;
		}
		sum += n%10;
		n = n/10;
	}
	return sum;
}