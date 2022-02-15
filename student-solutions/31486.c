int digitSum(int n)
{
	//Write solution here
    if(n<10) 
	  return n;
	 
	n =  digitSum(n/10) + (n % 10);
	return digitSum(n);
}