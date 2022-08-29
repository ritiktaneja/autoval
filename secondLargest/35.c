/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)//compute and print of second largest number among these
{    int a,b,c,d;
     scanf("%d%d%d%d",&a,&b,&c,&d); //input
     if((a<b)&&(a>c)&&(a>d)) //1st possible case
     return("The second largest number is %d",a);
     if((a>b)&&(a<c)&&(a>d)) //2nd possible case
     return("The second largest number is %d",a);
     if((a>b)&&(a>c)&&(a<d)) //3rd possible case
     return("The second largest number is %d",a);
     if((b<a)&&(b>c)&&(b>d)) //4th possible case
     return("The second largest number is %d",b);
     if((b>a)&&(b<c)&&(b>d)) //5th possible case
     return("The second largest number is %d",b);
     if((b>a)&&(b>c)&&(b<d)) //6th possible case
     return("The second largest number is %d",b);
     if((c<a)&&(c>b)&&(c>d)) //7th possible case
     return("The second largest number is %d",c);
     if((c>a)&&(c<b)&&(c>d)) //8th possible case
     return("The second largest number is %d",c);
     if((c>a)&&(c>b)&&(c<d)) //9th possible case
     return("The second largest number is %d",c);
     if((d<a)&&(d>b)&&(d>c)) //10th possible case
     return("The second largest number is %d",d);
     if((d>a)&&(d<b)&&(d>c)) //11th possible case
     return("The second largest number is %d",d);
     if((d>a)&&(d>b)&&(d<c)) //12th possible case
     return("The second largest number is %d",d);
    //return 0;
}