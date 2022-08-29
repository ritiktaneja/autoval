/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d){
    int a,b,c,d;
    scanf("%d %d %d %d",&a, &b, &c, &d);
    if((a<b)&&(a<c)&&(a<d))
    {
        if((b<c)&&(b<d))
    {
        if(c<d) {
       return("%d %d %d %d",a,b,c,d);
        }}
    }
        //return 0;
    }