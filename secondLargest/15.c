/*execute-result:OK*/
/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{int x,y,z,w;
scanf("%d %d %d %d", &x,&y,&z,&w); //getting input from the user
    if(x>y && x>w && x>z){ //condition when x is maximum
        if(y>z && y>w)
            return("\nThe second largest number is %d", y);
         if(w>y && w>z)
            return("\nThe second largest number is %d", w);
          if(z>w && z>y)
            return("\nThe second largest number is %d", z);
        }
     if(y>x && y>w && y>z){  //condition when y is maximum
        if(x>z && x>w)
            return("\nThe second largest number is %d", x);
         if(w>x && w>z)
            return("\nThe second largest number is %d", w);
          if(z>w && z>x)
            return("\nThe second largest number is %d", z);
        }
     if(z>y && z>w && z>x){  //condition when z is maximum
        if(y>x && y>w)
            return("\nThe second largest number is %d", y);
         if(w>y && w>x)
            return("\nThe second largest number is %d", w);
          if(x>w && x>y)
            return("\nThe second largest number is %d", x);
        }
     if(w>y && w>x && w>z){ //condition when w is maximum
        if(y>z && y>x)
            return("\nThe second largest number is %d", y);
         if(x>y && x>z)
            return("\nThe second largest number is %d", x);
          if(z>x && z>y)
            return("\nThe second largest number is %d", z);
        }
     if(x==y && x>z && x>w){//condition of equality
         if(z>w)
          return("The second largest number is %d", z);
          else
          return("The second largest number is %d", w);
     }   
          if(z==y && z>x && z>w){//condition of equality
         if(x>w)
          return("The second largest number is %d", x);
          else
          return("The second largest number is %d", w);
     }   
        if(x==z && x>y && x>w){//condition of equality
         if(y>w)
          return("The second largest number is %d", y);
          else
          return("The second largest number is %d", w);
     }
          if(z==w && z>x && z>y){//condition of equality
         if(x>y)
          return("The second largest number is %d", x);
          else
          return("The second largest number is %d", y);
     }  
          if(x==w && x>z && x>y){//condition of equality
         if(z>y)
          return("The second largest number is %d", z);
          else
          return("The second largest number is %d", y);
     }   
          if(w==y && w>z && w>x){//condition of equality
         if(z>x)
          return("The second largest number is %d", z);
          else
          return("The second largest number is %d", x);
     }   
          if(z==w && z>x && z>y){//condition of equality
         if(x>y)
          return("The second largest number is %d", x);
          else
          return("The second largest number is %d", y);
     }   





    //return 0;
}