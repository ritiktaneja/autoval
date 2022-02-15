int digitSum(int n)
{
	//Write solution here
    if(n < 10)
    {
        return n;
    }
    else
    {
        int rem = n % 10;
        int quot = n / 10;
        return digitSum(rem + digitSum(quot));
    }
}
