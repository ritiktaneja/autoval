int digSum(int n)
{
    int sum = 0;
    
    while(sum > 9 || n > 0 )
    {
        if(0 == n)
        {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}