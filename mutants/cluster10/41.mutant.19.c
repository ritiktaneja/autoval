int digitSum(int n)
{
int m,sum;
	if(n>0)    
  {    
     m=n%10;    
     sum=sum+m;    
      n=n/10;    
   } 
if(sum < 0)
   {
      return sum;
   }
else
   {
return digitSum(sum);
   }
}