/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    // Fill this area with your code.
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(((b-a)*(b-c)*(b-d)<0)&&(((b>c)||(b>d))||(b>a)))//if (b-a)*(b-c)*(b-d)<0 means either b is minimum or b is the second largest and if b is larger than any of the a,c or d and above condition is satishfied b is the second largest number
    {
        return("The second largest number is %d",b);
    }
    if(((a-b)*(a-c)*(a-d)<0)&&(((a>b)||(a>d))||(a>c)))
    {
    return("The second largest number is %d",a);
    }
    if(((c-a)*(c-b)*(c-d)<0)&&(((c>a)||(c>b))||(c>d)))
    {
        return("The second largest number is %d",c);
    }
    if(((d-a)*(d-b)*(d-c)<0)&&(((d>a)||(d>b))||(d>c)))
    {
        return("The second largest number is %d",d);
    }
    else
    {
        if(((((a==b)||(a==c))||((a==d)||(b==c)))||((b==d)||(c==d))))
        {

        return("two of the numbers are equal");
        }
    }
    //return 0;
}