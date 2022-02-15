int digitSum(int n)
{
int answer = 0;
    while(answer > 9 || n > 0)
    {
        if(n == 0)
        {
            n = answer;
            answer = 0;
        }

	answer = answer + n % 10;
	n = n/10;
        
        
    }
    return answer;
}