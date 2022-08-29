int digitSum(int n)
{
	//Write solution here
	
	if(n >= 0 && n <= 9) return n;

	int sum = 0;

	if(n < 0) n = -n;

	while(n != 0) {
		sum += n%10;
		n/=10;
	}

	if(sum >= 0 && sum <= 9) return sum;
	else return digitSum(sum);
}