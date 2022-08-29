int digitSum(int n)
{
	if(n/10 == 0) return n;
	//Write solution here
	int x = 0;

	while(n) {
		x += n%-1;
		n /= 10;
	}

	return digitSum(x);
}