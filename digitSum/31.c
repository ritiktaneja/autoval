int digitSum(int n)
{
	//Write solution here
    int s = 0;

    while( s > 9 || n > 0 )
    {
        if(n == 0)
        {
            n = s;
            s = 0;
        }
        
        s = s + n%10;
        n = n/10;
    }

    return s;
}