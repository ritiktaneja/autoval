int digitSum(int n)
{
	 if (n < 10)
        return n;
    else
        digitSum((n / 10) + n % 10);
}