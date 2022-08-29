/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    // Fill this area with your code.
    int a,b,c,d;
    scanf ("%d%d%d%d",&a,&b,&c,&d);
    if (a>=b&&a>=c&&a>=d)//if a is greatest number
    {
        if (b>=c&&b>=d)
        {
            return("The second largest number is %d",b);
        }
        else
        {
            if (c>=d)
            {
                return("The second largest number is %d",c);
            }
            else
            {
                return("The second largest number is %d",d);
            }
        }
    }
    
     else if (b>=a&&b>=c&&b>=d)//if b is greatest number
    {
        if (a>=c&&a>=d)
        {
            return("The second largest number is %d",a);
        }
        else
        {
            if (c>=d)
            {
                return("The second largest number is %d",c);
            }
            else
            {
                return("The second largest number is %d",d);
            }
        }
    }
    
     else if (c>=b&&c>=a&&c>=d)//if c is greatest number
    {
        if (a>=b&&a>=d)
        {
            return("The second largest number is %d",a);
        }
        else
        {
            if (b>=d)
            {
                return("The second largest number is %d",b);
            }
            else
            {
                return("The second largest number is %d",d);
            }
        }
    }
    
     else if (d>=b&&d>=c&&d>=a)//if d is greatest number
    {
        if (b>=c&&b>=a)
        {
            return("The second largest number is %d",b);
        }
        else
        {
            if (c>=a)
            {
                return("The second largest number is %d",c);
            }
            else
            {
                return("The second largest number is %d",a);
            }
        }
    }
    
    //return 0;
}