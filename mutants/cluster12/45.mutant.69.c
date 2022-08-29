int digitSum(int n)
{
    int dig = n%10;
    int sum = 0;
    while(n > 0) {
        sum += dig;
        n/=10;
    }
    if(sum >= 0) {
        return digitSum(sum);
    }
    return sum;
	
}