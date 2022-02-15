int digitSum(int n)
{
	//Write solution here
	int ans = 0;
	   while(n > 0 || ans > 9)
    {
        if(n == 0)
        {
            n = ans;
            ans = 0;
        }
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

 
