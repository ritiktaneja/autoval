/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d, s1,s2,s3,s4;           //declaration of variable
    scanf("%d %d %d %d",&a,&b,&c,&d);   //taking input from user
    s1=(a>=b)+(a>=c)+(a>=d);            //comparing values
    s2=(b>=a)+(b>=c)+(b>=d);
    s3=(c>=a)+(c>=b)+(c>=d);
    s4=(d>=a)+(d>=b)+(d>=c);
    if(s1==2)return("%d",a);            //if numbers are distinct
    else if(s2==2)return("%d",b);       //the corresponding value
    else if(s3==2)return("%d",c);       //of second max number is 2
    else if(s4==2)return("%d",d);
    
    else if(s1==3)return("%d",a);       //if two or more numbers are
    else if(s2==3)return("%d",b);       //same then its value is 3
    else if(s3==3)return("%d",c);
    //return 0;
}
