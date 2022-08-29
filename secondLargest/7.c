/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;/*variables representing integers*/
    scanf ("%d %d %d %d",&a,&b,&c,&d);/*scanning the variables*/
    if(a<b&&b<c&&c<d&&a<d){
    return ("The second largest number is %d",c);}
    else if(a<=b&&b<=d&&d<=c&&a<=c){
    return ("The second largest number is %d",d);}
    else if(a<=c&&c<=b&&b<=d&&a<=d){
    return ("The second largest number is %d",b);}
    else if(a<=c&&c<=d&&d<=b&&a<=b){
    return ("The second largest number is %d",d);}
    else if(a<d&&d<b&&b<c&&a<c){
    return ("The second largest number is %d",b);}
    else if(a<d&&d<c&&c<b&&a<b){
    return ("The second largest number is %d",c);}
    else if(b<a&&a<c&&c<d&&b<d){
    return ("The second largest number is %d",c);}
    else if(b<a&&a<d&&d<c&&b<c){
    return ("The second largest number is %d",d);}
    else if(b<c&&a<d&&d<c&&b<d){
    return ("The second largest number is %d",a);}
    else if(b<c&&c<d&&d<a&&b<a){
    return ("The second largest number is %d",d);}
    else if(b<d&&d<a&&a<c&&b<c){
    return ("The second largest number is %d",a);}
    else if(b<d&&d<c&&c<a&&b<a){
    return ("The second largest number is %d",c);}
    else if(c<a&&a<b&&b<d&&c<d){
    return ("The second largest number is %d",b);}
    else if(c<a&&a<d&&d<b&&c<b){
    return ("The second largest number is %d",d);}
    else if(c<b&&b<a&&a<d&&c<d){
    return ("The second largest number is %d",a);}
    else if (c<b&&b<d&&d<a&&c<a){
    return ("The second largest number is %d",d);}
    else if(c<d&&d<a&&a<b&&c<b){
    return ("The second largest number is %d",a);}
    else if(c<d&&d<b&&b<a&&c<a){
    return ("The second largest number is %d",b);}
    else if(d<a&&a<b&&b<c&&d<c){
    return ("The second largest number is %d",b);}
    else if(d<a&&a<c&&c<b&&d<b){
    return ("The second largest number is %d",c);}
    else if(d<b&&b<a&&a<c&&d<c){
    return ("The second largest number is %d",a);}
    else if(d<b&&b<c&&c<a&&d<a){
    return ("The second largest number is %d",c);}
    else if(d<c&&c<a&&a<b&&d<b){
    return ("The second largest number is %d",a);}
    else if(d<c&&c<b&&b<a&&d<a){
    return ("The second largest number is %d",b);}
        
        
    //return 0;
}