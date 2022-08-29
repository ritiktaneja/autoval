/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);//all nos are scanned
if(a>b)
   {
       if(b>c)
       {    if(b>d)
           {
               return("The second largest number is %d",b);
               
           }
            else
           {
               if(a>d)
                    {
                        return("The second largest number is %d",d);
                    
                    }
                 else
                  {
                    return("The second largest number is %d",a);
                      
                  }
               
           }
       }
     else
     {
         if(a>c)
            {
                if(d>c)
                {
                    if(d>a)
                    {
                        return("The second largest number is %d",a);
                        
                    }
                     else
                    {
                        return("The second largest number is %d",d);
                    }
                }
            else
                {
                    return("The second largest number is %d",c);
                }
            }
        else
            {
                if(d>a)
                {
                    if(d>c)
                    {
                        return("The second largest number is %d",c);
                    }
                     else
                     {
                     return("The second largest number is %d",d);
                    } 
                }
             else
                 {
                 return("The second largest number is %d",a);
                 
                  }   
            }
     }  
   }
else
    {
        if(a>c)
        {
            if(a>d) 
            {
                return("The second largest number is %d",a);
            }
        else
             {
                 if(b>d)
                  {
                      return("The second largest number is %d",d);
                  }
              else
                  {
                      return("The second largest number is %d",b);
                  }
             }    
        }
    else
        {
            if(b>c)
            {
                if(b>d)
                {   if (d>c)
                        {
                            return("The second largest number is %d",d);
                            
                        }
                     else
                        {
                            return("The second largest number is %d",c);
                        }
                }
            else
                {
                    return("The second largest number is %d",b);
                    
                }
            }    
        else
            {if (c>d)
                {if(d>b){return("The second largest number is %d",d);}
                 else 
                 {return("The second largest number is %d",b);}
                }   
            else{return("The second largest number is %d",c);}    
            }    
        }    
    }   //return 0;//to find the second largest number,we have used nested if else statements in this case
}