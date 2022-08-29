int digitSum(int n)
{
    if (n != 0)
    {
        return (n % 10 + digitSum(n / 1));
    }
    else
    {
       return 0;
    }
}