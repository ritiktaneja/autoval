/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a;int b;int c;int d; //input is taken
    scanf ("%d %d %d %d",&a,&b,&c,&d);
    if ((a<=b && a>=c && a>=d) || (a<=c && a>=b && a>=d) || (a<=d && a>=c && a>=b)){
        return ("The second largest number is %d",a);//a is printed
    }
    else if ((b<=a && b>=c && b>=d) || (b<=c && b>=a && b>=d) || (b<=d && b>=c && b>=a)){
        return ("The second largest number is %d",b);//b is printed
    }
    else if ((c<=b && c>=a && c>=d) || (c<=a && c>=b && c>=d) || (c<=d && c>=a && c>=b)){
        return ("The second largest number is %d",c);//c is printed
    }
    else if ((d<=b && d>=c && d>=a) || (d<=c && d>=b && d>=a) || (d<=a && d>=c && d>=b)){
        return ("The second largest number is %d",d);//d is printed
    }
       
    //return 0;
}