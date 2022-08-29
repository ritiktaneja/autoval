/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
//We are dealing with a programming to find the second largest numbers... 
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a, b, c, d;//a, b, c, d are 4 natural nos.
    
    scanf("%d %d %d %d",&a, &b, &c, &d);//Will take the input from                                                 the users.
    if(a>b>c>d){
        return("The second largest number is %d",c);}
    else if(a>b>d>c){
        return("The second largest number is %d",d);}
    else if(a>c>b>d){
        return("The second largest number is %d",b);}
    else if(a>c>d>b){
        return("The second largest number is %d",d);}
    else if(a>d>b>c){
        return("The second largest number is %d",b);}
    else if(a>d>c>b){
        return("The second largest number is %d",c);}
    else if(b>c>d>a){
        return("The second largest number is %d",d);}
    else if(b>c>a>d){
        return("The second largest number is %d",a);}
    else if(b>a>c>d){
        return("The second largest number is %d",c);}
    else if(b>a>d>c){
        return("The second largest number is %d",d);}
    else if(b>d>a>c){
        return("The second largest number is %d",a);}
    else if(b>d>c>a){
        return("The second largest number is %d",c);}
    else if(c>d>a>b){
        return("The second largest number is %d",a);}
    else if(c>d>b>a){
        return("The second largest number is %d",b);}
    else if(c>a>b>d){
        return("The second largest number is %d",b);}
    else if(c>a>d>b){
        return("The second largest number is %d",d);}
    else if(c>b>a>d){
        return("The second largest number is %d",a);}
    else if(c>b>d>a){
        return("The second largest number is %d",d);}
    else if(d>a>b>c){
        return("The second largest number is %d",b);}
    else if(d>a>c>b){
        return("The second largest number is %d",c);}
    else if(d>b>a>c){
        return("The second largest number is %d",a);}
    else if(d>b>c>a){
        return("The second largest number is %d",c);}
    else if(d>c>a>b){
        return("The second largest number is %d",a);}
    else{
        return("The second largest number is %d",b);}
        

    //return 0;
}