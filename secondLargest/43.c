/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);//a,b,c,d are natural number
if((a>b)&&(b>c)&&(b>d)){return("The second largest number is %d",b);}
if((a<b)&&(a>d)&&(a>c)){return("The second largest number is %d",a);}
if((a>c)&&(c>b)&&(c>d)){return("The second largest number is %d",c);}
if((a<c)&&(a>b)&&(a>d)){return("The second largest number is %d",a);}
if((a>d)&&(d>b)&&(d>c)){return("The second largest number is %d",d);}
if((a<d)&&(a>b)&&(a>c)){return("The second largest number is %d",a);}
if((a<d)&&(a>b)&&(a>c)){return("The second largest number is %d",a);}
if((b>c)&&(c>b)&&(c>a)){return("The second largest number is %d",c);}
if((b<c)&&(b>a)&&(b>d)){return("The second largest number is %d",b);}
if((b>d)&&(d>a)&&(d>c)){return("The second largest number is %d",d);}
if((b<d)&&(b>a)&&(b<c)){return("The second largest number is %d",b);}
if((c>d)&&(d>a)&&(d>b)){return("The second largest number is %d",d);}
if((c<d)&&(c>b)&&(c>a)){return("The second largest number is %d",c);}
if(a==b==c){if(d>a)return("The second largest number is %d",c);}
if(b==c==d){if(a>b)return("The second largest number is %d",c);}
if(a==b==d){if(c>b)return("The second largest number is %d",a);}
if(a==d==c){if(d>b)return("The second largest number is %d",c);}
if(a==b==c==d){return("The second largest number is %d",c);}
if((a==b)&&(c==d)&&(a>c)){if(d>b)return("The second largest number is %d",c);}
//return 0;
}