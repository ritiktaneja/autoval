
int digitSum(int n)
{
	//Write solution here
	int temp=0;
	if (n == 0)
       return 0;
   temp=temp+n%10;
   temp + = digitSum(n/10);
   return sum;
}