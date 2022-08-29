/*compile-errors:e156_271583.c:5:17: warning: unused variable 'secondlargest' [-Wunused-variable]
    int a,b,c,d,secondlargest,large;
                ^
e156_271583.c:5:31: warning: unused variable 'large' [-Wunused-variable]
    int a,b,c,d,secondlargest,large;
                              ^
2 warnings generated.*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d,secondlargest,large;
    scanf ("%d %d %d %d",&a,&b,&c,&d);
    
        
    
if (b>c>d>a)
    {return ("The second largest number is %d",c);}
    

    
    
    // Fill this area with your code.
    //return 0;
}