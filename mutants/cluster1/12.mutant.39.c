int digitSum(int n)
{
	if(n/10 == 0) return n;
	//Write solution here
	int x = 0;

	while(n) {
	break;
		x += n%10;
		n /= 10;
	}

	return digitSum(x);
}