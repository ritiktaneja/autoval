int digitSum(int n)
{
    if (n != 1)
    {
        return (n % 10 + digitSum(n / 10));
    }
    else
    {
       return 0;
    }
}