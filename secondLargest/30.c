/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
   int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    /*max1- to store greatest number 
      max2- to store second greatest number*/
    int max1=a;
    int max2=0;
    //finding greatest number.
    if(b>max1)
    { 
        max1=b;
        
    }
    if(c>max1) 
    {
        max1=c;
        
    }
    if(d>max1)
    {
        max1=d;
        
    }
    
    //searching for second greatest number.
    if(b!=max1)
    {
        max2=b;
        if((a>max2)&&(a!=max1))
        {
            max2=a;
        }
        if((c>max2)&&(c!=max1))
        {
            max2=c;
        }
        if((d>max2)&&(d!=max1))
        {
            max2=d;
        }
        
    }
    else
    {
        max2=a;
        if(c>max2)
        {
            max2=c;
        }
        if(d>max2)
        {
            max2=d;
        }
        
    }
    //printing second highest number.
    
    return("The second largest number is %d",max2);
   
    //return 0;
   
}