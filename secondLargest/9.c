/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d; int k=0;
    
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    if(a>=b)   //these nested ifs check if a is second largest or not
    {
        if(a>=c)
        {
            if(a<=d&&k!=1)
           { return("%d",a);k=1;}           
        }    
        else
        {
        
            if(a>=d&&k!=1)
           { return("%d",a);k=1;}
        }
    
    }
    else
    {
        if(a>=c)
        {
            if(a>=d&&k!=1)
            {return("%d",a);k=1;}
        }
    }
    
    
    
    
    if(b>=a)
    {                             //nested ifs to check if b is second
                                  //largest or not
        if(b>=c)
        {
            if(b<=d&&k!=1)
            {return("%d",b);k=1;}
            
        }
        else
        {
            if(b>=d&&k!=1)
            {return("%d",b);k=1;}
        }    
    }
    else
    {
        if(b>=c)
        {
            if(b>=d&&k!=1)
            {return("%d",b);k=1;}
        }
    }
    
    
    //checking if c is the required output or not
    if(c>=a)
    {
        if(c>=b)
        {
            if(c<=d&&k!=1)
            {return("%d",c);k=1;}
            
        }
        else
        {
            if(c>=d&&k!=1)
            {return("%d",c);k=1;}
            
        }
    }
    else
    {
        if(c>=b)
        {
            if(c>=d&&k!=1)
            {return("%d",c);k=1;}
            
        }
    }
    
    
    
    
    
    if(d>=a)          //now checking for d
    {
        if(d>=b)
        {
            if(d<=c&&k!=1)
            {return("%d",d);k=1;}
            
        }
        else
        {
            if(d>=c&&k!=1)
            {return("%d",d);k=1;}
            
        }
    }
    else
    {
        if(d>=b)
        {
            if(d>=c&&k!=1)
            {return("%d",d);k=1;}
            
        }
    }
    
     
     
    
    if(a==b)       //dealing with special case if 2 nos are equal
    {
        if(a>c&&a>d)
        return("%d",a);
    }    
    if(a==c)
    {
        if(a>b&&a>d)
        return("%d",a);
    }
    if(b==c)
     {
         if(b>a&&b>d)
         return("%d",b);
         
     }
    
    //return 0;
}
