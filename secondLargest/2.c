/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{   int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);//input the numbers
    int g1=a,g2=c,s;
    if(b>a)
       {g1=b;
        b=a;
       }//g1 stores greatest and b stores lowest among a and b
    if(d>g2)
       {g2=d;
        d=c;
       }//g2 stores greatest and d stores lowest among c and d
    if(g1>g2)//now b or g2 can be second largest 
       {if(b>g2)
          s=b;
        else
          s=g2;
       }
    else//now d or g1 can be second largest
       {if(d>g1)
          s=d;
        else
          s=g1;
       }
    return("The second largest number is %d",s);   
    //return 0;
}