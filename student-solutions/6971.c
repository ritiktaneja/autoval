
int digitSum(int n)
{
    if(n == 0) return 0;
    int sum = digitSum(n/10);
    sum += n%10;
    if(sum < 10) return sum;
    return digitSum(sum);

}


