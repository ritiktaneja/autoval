int digitSum(int n)
{
	int sum = 0;
	while(n!=0){
		sum+=n%10;
		n = n/10;
	}

	if(sum<=9)
		return sum;
	return digitSum(sum);
}

