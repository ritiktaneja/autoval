/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{ int a; int b; int c; int d;
int i; //the second largest number is to be stored
scanf("%d %d %d %d",&a,&b,&c,&d); //taking inputs
if(a>b){
    if(b>c && b>d){i=b;}
}
if(c>b){
    if(b>a && b>d){i=b;}
}
if(d>b){
    if(b>c && b>a){i=b;}
}
if(b>a){
    if(a>c && a>d){i=a;}
}
if(c>a){
    if(a>b && a>d){i=a;}
}
if(d>a){
    if(a>c && a>b){i=a;}
}
if(b>c){
    if(c>a && c>d){i=c;}
}
if(a>c){
    if(c>b && c>d){i=c;}
}
if(d>c){
    if(c>a && c>b){i=c;}
}
if(b>d){
    if(d>a && d>c){i=d;}
}
if(a>d){
    if(d>b && d>c){i=d;}
}
if(c>d){
    if(d>a && d>b){i=d;}
}
return("The second largest number is %d",i); //taking the output

    //return 0;
}