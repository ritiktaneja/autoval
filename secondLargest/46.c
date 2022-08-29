/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a, b, c, d;                                 /*decaration of variables*/                      
    int max1,max2,max3;                             /*variables to arrange the numbers*/
    scanf("%d %d %d %d",&a,&b,&c,&d);               /*input of numbers */
    if((a>b) && (b>c))                                  /*first 3 no.s are sorted*/
    {
        max1=a;                                     
        max2=b;
        max3=c; 
    }
    else if((a<b) && (b<c))
    {
        max1=c;
        max2=b;
        max3=a;
    }
    else if((a<b) && (c<b) && (a!=c))
    {
        if(a>c)
        {
            max1=b;
            max2=a;
            max3=c;
        }
        else
        {
            max1=b;
            max2=c;
            max3=a;
        }
    }
    else if((a>b) && (c>b) && (a!=c))
    {
        if(a>c)
        {
            max1=a;
            max2=c;
            max3=b;
        }
        if(c>a)
        {
            max1=c;
            max2=a;
            max3=b;
        }
    }
    else if((a==b) && (b!=c))
    {
        if(b>c)
        {
            max1=a;
            max2=c;
            
        }
        if(b<c)
        {
            max1=c;
            max2=a;
            max3=b;
        }
    }
    else if((b==c) && (b!=a))
    {
        if(a>b)
        {
            max1=a;
            max2=b;
        }
        if(b>a)
        {
            max1=b;
            max2=a;
        }
    }
    else if((a==c) && (b!=c))
    {
        if(b>c)
        {
            max1=b;
            max2=c;
        }
        if(c>b)
        {
            max1=c;
            max2=b;
        }
    }
    else 
    {
        if(d>a)
        {
            max1=d;
            max2=a;
        }
        else
        {
            max1=a;
            max2=d;
        }
    }
    if(d>max1) 
    {                                                  /*now comparision with the 4th digit*/
         return("The second largest number is %d",max1);
    }
    if((d<max1) && (d>=max2))
    {
         return("The second largest number is %d",d);
    }
    if((d<max2) || (d==max1))
    {
         return("The second largest number is %d",max2);
    }
    //return 0;
}