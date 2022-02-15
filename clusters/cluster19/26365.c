int digSum(int n)
{
    if (n == 0)
       return 0;
    return digSum((digSum(n/10) + n%10));
}