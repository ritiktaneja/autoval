/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (a<b)
    {
    if (a<c)
    {
    if (b<c)
    {
    if (c<d)
    {
    return("The second largest number is %d",c);    
    }
    else
    {
    if (b<d)
    {
    return("The second largest number is %d",d);    
    }
    else
    {
    return("The second largest number is %d",b);
    }
    }
    }
    else
    {
    if (b<d)
    {
    return("The second largest number is %d",b);
    }
    else
    {
    if (c<d)
    {
    return("The second largest number is %d",d);    
    }
    else
    {
    return("The second largest number is %d",c);    
    }
    }
    }
    }
    else
    {
    if (b<d)
    {
    return("The second largest number is %d",b);    
    }
    else
    {
    if (a<d)
    {
    return("The second largest number is %d",d);    
    }
    else
    {
    return("The second largest number is %d",a);    
    }
    }
    }
    }
    else
    {
     if (b<c)
    {
    if (a<c)
    {
    if (c<d)
    {
    return("The second largest number is %d",c);    
    }
    else
    {
    if (d<a)
    {
    return("The second largest number is %d",a);    
    }
    else
    {
    return("The second largest number is %d",d);
    }
    }
    }
    else
    {
    if (a<d)
    {
    return("The second largest number is %d",a);    
    }
    else
    {
    if (c<d)
    {
    return("The second largest number is %d",d);    
    }
    else
    {
    return("The second largest number is %d",c);    
    }
    }
    }
    }
    else
    {
    if (a<d)
    {
    return("The second largest number is %d",a);    
    }
    else
    {
    if (b<d)
    {
    return("The second largest number is %d",d);    
    }
    else
    {
    return("The second largest number is %d",b);    
    }
    }
    }
    }
    //return 0;
    }