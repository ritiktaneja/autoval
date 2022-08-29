/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
  
 int a,b,c,d,e1,e2,f1,f2,g;
 scanf("%d %d %d %d",&a,&b,&c,&d);
 
    
    
    if (a<b)
    {
         /*b is selected*/
         e1=b;
         e2=a;
    }
    else 
    {    /*a is selected*/
         e1=a;
         e2=b;
    }
  
    if (c<d)
    {
        /*d is selected*/
         f1=d;
         f2=c;
    }
    else
    {   /*c is selected*/
         f1=c;
         f2=d;
    }
    if (e1<f1)
    {   /*e1 is selected*/
         g=e1;
    }
    else 
    {   /*f1 is selected*/
         g=f1;
    }
  
  
  
  
  
  
  if (g<e2||g<f2)
  {   
    /*comparision between e2 and f2*/
    /*as g 'may' not be the second greatest number*/
      
      
        if (g<f2)
        {
            return("The second largest number is %d",f2);
        }
        else 
        {
            return("The second largest number is %d",e2);
        }
  }
  
  
  else
  {
            return("The second largest number is %d",g);
  }
 
    
    
    
    
    
    
    //return 0;
}