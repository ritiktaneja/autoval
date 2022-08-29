int digitSum(int n)
{
int m,sum;
	while(n>0)    
  {    
     m=n%10;    
     sum=sum+m;    
      n=n/10;    
      break;
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