int digitSum(int n)
{
    if(n<10)return n;
    int x=0;
    while(n)
    {
        x+=n%10;
        n/=10;
    }
    return digitsum(x);
}