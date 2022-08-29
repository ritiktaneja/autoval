int digitSum(int n)
{
	int h = 0;
	if(n/10 == 0)
		return n;
	int ten = 10;
	while(n != 0) {
		h += n%10;
		n /= 10;
	}
	return digitSum(h);
}