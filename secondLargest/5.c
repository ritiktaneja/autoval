/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d,x,y,z,w;
    scanf ("%d %d %d %d", &a , &b , &c , &d );
    if
    (a>b)
    {if (a>c) x=a;
    else x=c;
        
    } 
    else 
    {if (c>b) x=c;
        else x=b;
    }
    if 
    (b>c)
    {if (b>d) y=b;
    else y=d;
    
    }
    else
    { if (d>c) y=d;
    else y=c;
        
    }
    if
    (c>d)
    {if (c>a) z=c;
    else z=a;
        
    }
    else 
    { if (a>d) z=d;
    else z=c;}
    if
    (d>a)
    {if (d>b) w=d;
    else w=b;
        
    }
    else 
    { if (b>a) w=b;
    else w=a;
        
    }
    
    if (x==y && x==z)
    return ("%d", w);
    
    if (y==z && y==w)
    return ("%d", x);
    
    if (z==w && z==x)
    return ("%d", y);
    
    if (w==x && w==y)
    return ("%d", z);
    
    //return 0;
}
