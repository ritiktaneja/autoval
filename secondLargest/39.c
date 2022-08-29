/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{int a,b,c,d;
scanf("%d %d %d %d",&a,&b,&c,&d); /*inputting variables*/
      if (a>=b) {/*comparing a and b*/
          if (a>=c) {/*comparing a and c*/
              if (a>=d) {/*comparing a and d*/
                  if (b>=c) {/*comparing b and c*/
                      if (b>=d) {/*comparing b and d*/
                          return("The second largest number is %d",b);}/*because a>b and b>c & b>d*/
                     else {
                          return("The second largest number is %d",d);}
                  }
                else {
                    if (c>=d) {return("The second largest number is %d",c); }
                    else {
                        return("The second largest number is %d",d); }
                }
              }
            else {
                return("The second largest number is %d",a); }
          }
        else {
            if (a>=d) {/*c>a>=b*/
                return("The second largest number is %d",a); }/*because b>a and a>c & a>d*/
            else {
                return("The second largest number is %d",d); }
        }
          }
    else {  
        if  (b>=c) {/*comparing b and c*/
              if (b>=d) {/*comparing b and d*/
                  if (c>=d) {/*comparing c and d*/
                      if (c>=a) {/*comparing c and a*/
                          return("The second largest number is %d",c);}
                     else {
                          return("The second largest number is %d",a);}
                  }
                else {
                    if (d>=a) {return("The second largest number is %d",d); }
                    else {
                        return("The second largest number is %d",a); }
                }
              }
            else {
                return("The second largest number is %d",b); }
        }
        else {
            if (c>=d) {
                if (b>=d) {
                return("The second largest number is %d",b); } 
                else {
                    return("The second largest number is %d",d);}
                }
            else {
                return("The second largest number is %d",c); }
        }
            }    

    //return 0;
}