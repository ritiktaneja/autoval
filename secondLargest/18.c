/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    scanf("%d""%d""%d""%d",&a,&b,&c,&d);
    if (a>b && b>c&& c>d)
    {
    return("The second largest number is %d",b);
    }
    if (b>a && a>c&&c>d)
    {
    return("The second largest number is %d",a);
    }
    if (a>c && c>b&&b>d)
    {
    return("The second largest number is %d",c);
    }
    if (b>c && c>a&&a>d)
    {
        return("The second largest number is %d",d);
    }
    if (c>a&&a>b&&b>d)
    {
        return("The second largest number is %d",a);
    }
    if (c>b&&b>a&&a>d)
    {
            return("The second largest number is %d",b);
    }
    if (b>c&&c>d&&d>a)
    {
            return("The second largest number is %d",c);
    }
    if (b>d&&d>c&&c>a)
    {
            return("The second largest number is %d",d);
    }
    if (c>b&&b>d&&d>a)
    {
            return("The second largest number is %d",b);
    }
    if (c>d&&d>b&&b>a)
    {
            return("The second largest number is %d",d);
    }
    if (d>b&&b>c&&c>a)
    {
            return("The second largest number is %d",b);
    }
    if (d>c&&c>b&&b>a)
    {
            return("The second largest number is %d",d);
    }
    if (a>c&&c>d&&d>b)
    {
                return("The second largest number is %d",c);
}
 if (a>d&&d>c&&c>b)
 {
             return("The second largest number is %d",d);
 }
 if(d>c&&c>a&&a>b)
 {
             return("The second largest number is %d",c);
 }
 if(d>a&&a>c&&c>b)
 {
             return("The second largest number is %d",a);
 }
 if(c>d&&d>a&&a>b)
 {
             return("The second largest number is %d",d);
}
if(c>a&&a>d&&d>b)
{
            return("The second largest number is %d",a);
}
if(a>b&&b>d&&d>c)
{
            return("The second largest number is %d",b);
}
if(a>d&&d>b&&b>c)
{
            return("The second largest number is %d",d);
}
if(b>a&&a>d&&d>c)
{
            return("The second largest number is %d",a);
}
if(b>d&&d>a&&a>c)
{
            return("The second largest number is %d",d);
}
if(d>a&&a>b&&b>c)
{
            return("The second largest number is %d",a);
}
if(d>b&&b>a&&a>c)
{
            return("The second largest number is %d",b);
}
//return 0;
}