int digitSum(int n)
{
	//Write solution here
	if (n == 0) {
		return 0;
	}
	if (n % 9 == 0) {
		return 9;
	}
	else return n % 9;

}