/*execute-result:OK*/
/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int x,y,z,w;
    scanf("%d%d%d%d",&x,&y,&z,&w);
    if(x<=y&&y<=z&&z<=w){return("The second largest number is %d",z);}
    else if(x<=y&&y<=w&&w<=z){return("The second largest number is %d",w);}
    else if(x<=w&&w<=y&&y<=z){return("The second largest number is %d",y);}                                                                        else if(w<=z&&z<=x&&x<=y){printf("The second largest number is %d",x);}
    else if(x<=z&&z<=y&&y<=w){return("The second largest number is %d",y);}
    else if(x<=z&&z<=w&&w<=y){return("The second largest number is %d",w);}
    else if(x<=y&&y<=z&&z<=w){return("The second largest number is %d",z);}
    else if(x<=w&&w<=z&&z<=y){return("The second largest number is %d",z);}
    else if(y<=w&&w<=x&&x<=z){return("The second largest number is %d",x);}
    else if(y<=w&&w<=z&&z<=x){return("The second largest number is %d",z);}
    else if(y<=z&&z<=x&&x<=w){return("The second largest number is %d",x);}
    else if(y<=z&&z<=w&&w<=x){return("The second largest number is %d",w);}
    else if(y<=x&&x<=w&&w<=z){return("The second largest number is %d",w);}
    else if(y<=x&&x<=z&&z<=w){return("The second largest number is %d",z);}
    else if(w<=x&&x<=y&&y<=z){return("The second largest number is %d",y);}
    else if(w<=x&&x<=z&&z<=y){return("The second largest number is %d",z);}
    else if(w<=y&&y<=x&&x<=z){return("The second largest number is %d",x);}
    else if(w<=y&&y<=z&&z<=x){return("The second largest number is %d",z);}
    else if(w<=z&&z<=y&&y<=x){return("The second largest number is %d",y);}
    else if(z<=x&&x<=w&&w<=y){return("The second largest number is %d",w);}
    else if(z<=x&&x<=y&&y<=w){return("The second largest number is %d",y);}
    else if(z<=y&&y<=x&&x<=w){return("The second largest number is %d",x);}
    else if(z<=y&&y<=w&&w<=x){return("The second largest number is %d",w);}
    else if(z<=w&&w<=x&&x<=y){return("The second largest number is %d",x);}
    else if(z<=w&&w<=y&&y<=x){return("The second largest number is %d",y);}
    // Fill this area with your code.
    //return 0;
}