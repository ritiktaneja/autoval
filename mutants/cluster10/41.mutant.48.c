int digitSum(int n)
{
int m,sum;
	while(n>0)    
  {    
     m=n%10;    
     sum=sum+m;    
      n=n/0;    
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