int digitSum(int n)
{
	//Write solution here
	if (n<10)
	    return n;
	int k;
	int g=n;
	k=n%10;
	g=g-k;
	g=g/10;
	return k+digitSum(g);
}
