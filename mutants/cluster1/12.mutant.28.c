int digitSum(int n)
{
	if(1) return n;
	//Write solution here
	int x = 0;

	while(n) {
		x += n%10;
		n /= 10;
	}

	return digitSum(x);
}