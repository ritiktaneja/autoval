/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
 int a,b,c,d;
 scanf("%d%d%d%d",&a,&b,&c,&d);
  if(a<=b){
      if(a<=c){
          if(b<=c){
              if(d<=c){
                  return("The second largest number is %d",b);}
                  else{
                     return("The second largest number is %d",c); 
                  }
                  
          }
      }
  }
    //return 0;
}