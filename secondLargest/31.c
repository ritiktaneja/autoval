/*execute-result:OK*/
/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;/*To store the four inputed integers.*/
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int n1;/*To store the larger among a and b.*/
    int n2;/*To store the smaller among a and b.*/
    if(a>b)
    { n1=a;
      n2=b;
      if(((c>b)&&(c>d))&&(c<a))
      { return("The second largest number is %d",c);
      }
      if(((c>a)&&(c>b))&&(c<d))
      { return("The second largest number is %d",c);
      }
      if(((d>b)&&(d>c))&&(d<a))
      { return("The second largest number is %d",d);
      }
      if(((d>a)&&(d>b))&&(d<c))
      { return("The second largest number is %d",d);
      }
      if((b>c)&&(b>d))
      { return("The second largest number is %d",b);
      }
      if((a>c)&&(a<d))
      { return("The second largest number is %d",a);
      }
      if((a<c)&&(a>d))
      { return("The second largest number is %d",a);
      }
    }
    else
    { n1=b;
      n2=a;
      if(((c>a)&&(c>d))&&(c<b))
      { return("The second largest number is %d",c);
      }
      if(((c>a)&&(c>b))&&(c<d))
      { return("The second largest number is %d",c);
      }
      if(((d>c)&&(d>a))&&(d<b))
      { return("The second largest number is %d",d);
      }
      if(((d>a)&&(d>b))&&(d<c))
      { return("The second largest number is %d",d);
      }
      if((a>c)&&(a>d))
      { return("The second largest number is %d",a);
      }
      if((b<c)&&(b>d))
      { return("The second largest number is %d",b);
      }
      if((b>c)&&(b<d))
      { return("The second largest number is %d",b);
      }
    }    
    //return 0;
}