/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
int a,b,c,d;// a,b,c,d are three natural number .
     scanf("%d %d %d %d",&a,&b,&c,&d);
if(((a>b)&&(a>c)&&(a<d))||((a>b)&&(a<c)&&(a>d))||((a<b)&&(a>c)&&(a>d)))
{
    return("The second largest number is %d",a);//a is second highest.
       }
else if(((b>a)&&(b>c)&&(b<d))||((b>a)&&(b<c)&&(b>d))||((b<a)&&(b>c)&&(b>d)))
{
    return("The second largest number is %d",b);//b is second highest.
       }
else if(((c>a)&&(c>b)&&(c<d))||((c>a)&&(c<b)&&(c>d))||((c<a)&&(c>b)&&(c>d)))
{
    return("The second largest number is %d",c);//c is second highest.
       }
else  
{
    return("The second largest number is %d",d);//d is second highest.
       }
    //return 0;
}