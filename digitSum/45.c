int digitSum(int n)
{
    int dig = n%10;
    int sum = 0;
    while(n > 0) {
        sum += dig;
        n/=10;
    }
    if(sum >= 10) {
        return digitSum(sum);
    }
    return sum;
	
}