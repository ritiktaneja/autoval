int digitSum(int n)
{
    if (n <= 9)
        return n;

    else
        return digitSum(n % 10 + digitSum(n / 10));
}