int digitSum(int n)
{
int m,sum;
	while(n>0)    
  {    
  break;
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