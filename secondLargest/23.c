/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if (((a>=b)&&(a>=c)&&(a<=d))||((a>=b)&&(a>=d)&&(a<=c))||((a>=c)&&(a>=d)&&(a<=b))){
        return("The second largest number is %d",a);
    }
    else if (((b>=a)&&(b>=c)&&(b<=d))||((b>=c)&&(b>=d)&&(b<=a))||((b>=d)&&(b>=a)&&(b<=c))){
        return("The second largest number is %d",b);
    }
    else if (((c>=a)&&(c>=b)&&(c<=d))||((c>=b)&&(c>=d)&&(c<=a))||((c>=d)&&(c>=a)&&(c<=b))){
        return("The second largest number is %d",c);
    }
    else if (((d>=a)&&(d>=b)&&(d<=c))||((d>=b)&&(d>=c)&&(d<=a))||((d>=c)&&(d>=a)&&(d<=b))){
        return("The second largest number is %d",d);
    }// a number will be second largest if it is greater than two numbers and less than the third number
    //return 0;
}