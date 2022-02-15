int digitSum(int n)
{
	//Write solution here
	if (n<10){return n;}

	int sum=0;
	int rem = 0;
	while (n>0){
		rem = n%10;
		sum = sum + rem;
		n = n - rem;
		n = n/10;

	}

	return digitSum(sum);
}