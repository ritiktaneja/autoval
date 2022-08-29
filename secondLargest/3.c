/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d,max,smax;
    
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    if((a>=b)&(a>=c)&(a>=d))
    max=a;
    else if((b>=a)&(b>c)&(b>d))
    max=b;
    else if((c>a)&(c>b)&(c>d))
    max=c;
    else
    max=d;
    
    if(a==max)
    {
        if((b>c)&(b>d))
        smax=b;
        else if((c>d)&(c>b))
        smax=c;
        else
        smax=d;
    }
    else if(b==max)
    {
        if((a>c)&(a>d))
        smax=a;
        else if((c>a)&(c>d))
        smax=c;
        else
        smax=d;
    }
    else if(c==max)
    {
        if((a>b)&(a>d))
        smax=a;
        else if((b>a)&(b>d))
        smax=b;
        else
        smax=d;
    }
    else
    {
        if((a>b)&(a>c))
        smax=a;
        else if((b>a)&(b>c))
        smax=b;
        else
        smax=c;
    }
    return("The second largest number is %d",smax);    // Fill this area with your code.
    //return 0;
}