/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d,i=0,z=0,k=0;// variables declared
    /* inputting four variables, i.e. four natural numbers*/
    scanf("%d%d%d",&a,&b,&c,&d);
    /* i would take a as first value and as it encounters a value          higher than itself, it would take that. i would finally store the      largest number. */
    if(a>i)
    {
        i=a;
    }
    if(b>i)
    {
        i=b;
    }
    if(c>i) //these four if find the maximum of four numbers
    {
        i=c;
    }
    if(d>i) 
    {
        i=d;
    }

    if(a<i && a>z) 
    {
        z=a;
    }
    if(b<i && b>z) 
    {
        z=b;
    }
    if(c<i && c>z) // these four if find the largest number excluding      the maximum number which is saved in i and saves it in z
    {
        z=c;
    }
    if(d<i && d>z)
    {
        z=d;
    }
    /*check how many numbers are there that are largest and store them     in k*/
    if(a==i)
    {
        ++k;
    }
    if(b==i)
    {
        ++k;
    }
    if(c==i)// these four if check if more than one value is maximum.      if more than one maximum, program needs to print the maximum number     as per the hidden test.
    {
        ++k;
    }
    if(d==i)
    {
        ++k;
    }
    // if more than one are maximum, store maximum in z
    if(k>1) 
    {
        z=i;
    }
    return("%d", z); // prints the value of z
    //return 0;
}
