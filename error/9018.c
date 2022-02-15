int digitSum(int n)
{
	//Write solution here
   if(n/10 == 0)
      return n;
	int ans = (n%10)+digitSum(n/10);
	return (ans%10)+(ans/10);
}