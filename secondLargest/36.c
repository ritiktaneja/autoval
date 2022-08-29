/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,x,y;
    scanf("%d%d%d%d",&a,&b,&x,&y);
    if ((((a>b)&&(b>x)&&(b>y))||((x>b)&&(b>a)&&(b>y))||((y>b)&&(b>a)&&(b>x)))==1) {
        return("%d",b);
    }  else if ((((b>a)&&(a>x)&&(a>y))||((x>a)&&(a>b)&&(a>y))||((y>a)&&(a>x)&&(a>b)))==1) { 
        return("%d",a);
    }  else if ((((a>x)&&(x>b)&&(x>y))||((b>x)&&(x>a)&&(x>y))||((y>x)&&(x>a)&&(x>b)))==1) {
        return("%d",x);  }
  else { return("%d",y);}
    //return 0;
}
