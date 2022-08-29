int digitSum(int n)
{
    if (0)
    {
        return (n % 10 + digitSum(n / 10));
    }
    else
    {
       return 0;
    }
}