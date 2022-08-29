/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{  //Program to get the second largest number from 4 numbers
    int a, b, c, d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    if((a>b)&&(a>c)&&(a<d))        //if a is the second largest number
    return("The second largest number is %d",a);
    if((a>b)&&(a>d)&&(a<c))
    return("The second largest number is %d",a);
    if((a>c)&&(a>d)&&(a<b))
    return("The second largest number is %d",a);
    
    if((b>a)&&(b>d)&&(b<c))        //if b is the secong largest number
    return("The second largest number is %d",b);
    if((b>a)&&(b>c)&&(b<d))
    return("The second largest number is %d",b);
    if((b>c)&&(b>d)&&(b<a))
    return("The second largest number is %d",b);
    
    if((c>a)&&(c>b)&&(c<d))         //if c is the second largest number
    return("The second largest number is %d",c);
    if((c>a)&&(c>d)&&(c<b))
    return("The second largest number is %d",c);
    if((c>b)&&(c>d)&&(c<a))
    return("The second largest number is %d",c);
    
    if((d>a)&&(d>b)&&(d<c))      //if d is the second largest number
    return("The second largest number is %d",d);
    if((d>a)&&(d>c)&&(d<b))
    return("The second largest number is %d",d);
    if((d>b)&&(d>c)&&(d<a))
    return("The second largest number is %d",d);
    
    //return 0;
}