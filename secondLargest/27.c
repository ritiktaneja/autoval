/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    //sorting
    if(b<a)
    {
        int z=a;
        a=b;
        b=z;
    }
     if(c<b)
    {
        int z=b;
        b=c;
        c=z;
    }
     if(d<c)
    {
        int z=c;
        c=d;
        d=z;
    }
     if(b<a)
    {
        int z=a;
        a=b;
        b=z;
    }
     if(c<b)
    {
        int z=b;
        b=c;
        c=z;
    }
     if(b<a)
    {
        int z=a;
        a=b;
        b=z;
    }
    //sorted increasing sequence a b c d
    //printing the second latgest i.e. c
    return("The second largest number is %d",c);
    //return 0;
}