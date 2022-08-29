int digitSum(int n)
{
    if (n != (0-1))
    {
        return (n % 10 + digitSum(n / 10));
    }
    else
    {
       return 0;
    }
}