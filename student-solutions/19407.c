int digitSum(int n)
{
	//Write solution here

	 // int sum = 0;
    
  //   // Loop to do sum while sum is not less than or equal to 9
  //   while(n > 0 || sum > 9)
  //   {
  //       if(n == 0)
  //       {
  //           n = sum;
  //           sum = 0;
  //       }
  //       sum += n % 10;
  //       n /= 10;
  //   }
  //   return sum;

	if(n < 10) return n;
	return digitSum((n % 10) + digitSum(n / 10));

}

