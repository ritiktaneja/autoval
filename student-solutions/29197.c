int digitSum(int n)
{
	//Write solution here
	int remainder=0;
    int sum=0;
    int a=0;
    while(n!=0)
    {
        remainder=n%10;
        sum+=remainder;
        n/=10;
    }
    //printf("Sum is %d", sum);
    
    if(sum>=10)
        a= sumOfDigits(sum);
    else
        return sum;
    
    return a;

}