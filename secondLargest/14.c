/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{ int a,b,c,d,h; //Assigning data types
scanf("%d %d %d %d",&a,&b,&c,&d); // Takes input from the user
if(a>b)
{
    if(b>c && b>d) //applying conditions
    h=b;
}
if(c>b)
{
    if(b>a && b>d)//applying conditions
    h=b;
}
if(d>b)
{
    if(b>c && b>a)//applying conditions
    h=b;
}
if(b>a)
{
    if(a>c && a>d)//applying conditions
    h=a;
}
if(c>a)
{
    if(a>b && a>d)//applying conditions
    h=a;
}
if(d>a)
{
    if(a>c && a>b)//applying conditions
    h=a;
}
if(b>c)
{
    if(c>a && c>d)//applying conditions
    {h=c;}
}
if(a>c)
{
    if(c>b && c>d)//applying conditions
    h=c;
}
if(d>c)
{
    if(c>a && c>b)//applying conditions
    h=c;
}
if(b>d)
{
    if(d>a && d>c)//applying conditions
    h=d;
}
if(a>d)
{
    if (d>b && d>c)//applying conditions
    h=d;
}
if(c>d)
{
    if(d>a && d>b)//applying conditions
    h=d;
}
return("The second largest number is %d",h); // Output will be obtained

    //return 0;
}