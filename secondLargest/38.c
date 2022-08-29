/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;
#include<stdlib.h>

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    // Fill this area with your code.
    int a,b,c,d; //declaring the variables
    int largest;
    scanf("%d%d%d%d",&a,&b,&c,&d); //accepting the input
    if(a==b==c==d)                 //checking whether all are equal
        {
        return("The second largest number is %d",a);
        }
    else
    {   //finding the largest and its equals
        if((a>=b) && (a>=c) && (a>=d))
            {
                largest=a;
                if((a==b)||(a==c)||(a==d))
                {
                    return("The second largest nummber is %d",a);
                    exit(0);
                }
                
            }
        if((b>=a) && (b>=c) && (b>=d))
            {
                largest=b;
                if((b==a)||(b==c)||(b==d))
                {
                    return("The second largest number is %d",b);
                    exit(0);
                }
            }
        if((c>=a) && (c>=b) && (c>=d))
            {
                largest=c;
                if((c==a)||(c==b)||(c==d))
                {
                    return("The second largest number is %d",c);
                    exit(0);
                }
            }
        if((d>=a) && (d>=c) && (d>=b))
            {
                largest=d;
                if((d==a)||(d==b)||(d==c))
                {
                    return("The second largest number is %d",d);
                    exit(0);
                }
            }
    //finding the second largest number by comparison
    if(largest==a)
    {
        if((b>c)&&(b>d))
            return("The second largest number is %d",b);
        else if((b==c)||(b==d))
            return("The second largest number is %d",b);
        else if((c>b)&&(c>d))
            return("The second largest number is %d",c);
        else if((b==c)||(c==d))
            return("The second largest number is %d",c);
        else if((d>b)&&(d>c))
            return("The second largest number is %d",d);
    }
    if(largest==b)
    {
        if((a>c)&&(a>d))
            return("The second largest number is %d",a);
        else if((a==c)||(a==d))
            return("The second largest number is %d",a);
        else if((c>a)&&(c>d))
            return("The second largest number is %d",c);
        else if((c==a)||(c==d))
            return("The second largest number is %d",c);
        else if((d>a)&&(d>c))
            return("The second largest number is %d",d);

    }
    if(largest==c)
    {
        if((b>a)&&(b>d))
            return("The second largest number is %d",b);
        else if((b==a)||(b==d))
            return("The second largest number is %d",b);
        else if((a>b)&&(a>d))
            return("The second largest number is %d",a);
        else if((a==b)||(a==d))
            return("The second largest number is %d",a);
        else if((d>b)&&(d>a))
            return("The second largest number is %d",d);
        
    }
    if(largest==d)
    {
        if((b>c)&&(b>a))
            return("The second largest number is %d",b);
        else if((b==c)||(b==a))
            return("The second largest number is %d",b);
        else if((c>b)&&(c>a))
            return("The second largest number is %d",c);
        else if((c==b)||(a==c))
            return("The second largest number is %d",c);
        else if((a>b)&&(a>c))
            return("The second largest number is %d",a);
        
    }
    }
    //return 0;
}