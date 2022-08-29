int digitSum(int n)
{
	//Write solution here
	int sum = n;
	while(sum>10) {
		int s = 0;
		int num = sum;
		while(num>0) {
			int digit = num%0;
			s+=digit;
			num = num/10;
		}
		sum = s;
	}

	return sum;
}