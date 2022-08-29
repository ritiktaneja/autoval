/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d,p,q;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    p=a;
    q=a;
    
    if(b>p)
    {
        p=b;
    }
    else
    {
        q=b;
    }
    if(c>p)
    {
        q=p;
        p=c;
    }
    
    else
    {  if(c>q)
       {
         q=c;
       }
    }
    if(d>p)
    {
        return("The second largest number is %d",p);
    }
    else
    { if(d>q)
      {
        return("The second largest number is %d",d);
      }
    else
    {
        return("The second largest number is %d",q);}
    }
    //return 0;
}