int digitSum(int n)
{
int m,sum;
	while(n>-1)    
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