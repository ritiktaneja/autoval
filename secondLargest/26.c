/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a, b, c, d;
    scanf("%d%d%d",&a,&b,&c,&d);
    if ((a>b) && (b>c) && (c>d)){
        //return("The second largest number is ");
        return("%d", b);
    }else{
        if ((a>b) && (b>d) && (d>c)){
            //return("The second largest number is ");
            return("%d", b);
        }else{
            if ((a>c) && (c>b) && (b>d)){
                //return("The second largest number is ");
                return("%d", c);
            }else{
                if ((a>c) && (c>d) && (d>b)){
                    //return("The second largest number is ");
                    return("%d", c);
                }else{
                 if ((a>d) && (d>b) && (b>c)){
                     //return("The second largest number is ");
                     return("%d", d);
                 }else{
                     if ((a>d) && (d>c) && (c>b)){
                         //return("The second largest number is ");
                         return("%d", d);
                     }else{
                         if ((b>a) && (a>d) && (d>c)){
                             //return("The second largest number is ");
                             return("%d", a);
                         }else{
                             if ((b>a) && (a>c) && (c>d)){
                                 //return("The second largest number is ");
                                 return("%d", a);
                             }else{
                                 if ((b>c) && (c>a) && (a>d)){
                                     //return("The second largest number is ");
                                     return("%d", c);
                                 }else{
                                     if ((b>c) && (c>d) && (d>a)){
                                         //return("The second largest number is ");
                                         return("%d", c);
                                     }else{
                                         if ((b>d) && (d>a) && (a>c)){
                                             //return("The second largest number is ");
                                             return("%d", d);
                                         }else{
                                             if ((b>d) && (d>c) && (c>a)){
                                                 //return("The second largest number is ");
                                                 return("%d", d);
                                             }else{
                                                 if ((c>a) && (a>b) && (b>d)){
                                                     //return("The second largest number is ");
                                                     return("%d",a);
                                                 }else{
                                                     if ((c>a) && (a>d) && (d>b)){
                                                         //return("The second largest number is ");
                                                         return("%d", a);
                                                     }else{
                                                         if ((c>b) && (b>a) && (a>d)){
                                                             //return("The second largest number is ");
                                                             return("%d", b);
                                                         }else{
                                                             if ((c>b) && (b>d) && (d>a)){
                                                                 
//return("The second largest number is ");
                                                                 printf("%d", b);
                                                             }else{
                                                                 if ((c>d) && (d>a) && (a>b)){
                                                                     
//return("The second largest number is ");
                                                                     printf("%d", d);
                                                                 }else{
                                                                     if ((c>d) && (d>b) && (b>a)){
                                                                         
   //return("The second largest number is ");
                                                                         printf("%d", d);
                                                                     }else{
                                                                         if ((d>a) && (a>b) && (b>c)){
                                                                             
       //return("The second largest number is ");
                                                                             printf("%d", a);
                                                                         }else{
                                                                             if ((d>a) && (a>c) && (c>b)){
                                                                                 
           //return("The second largest number is ");
                                                                                 printf("%d", a);
                                                                             }else{
                                                                                 if ((d>b) && (b>a) && (a>c)){
                                                                                     
               //return("The second largest number is ");
                                                                                     printf("%d", b);
                                                                                 }else{
                                                                                     if ((d>b) && (b>c) && (c>a)){
                                                                                         
                   //return("The second largest number is ");
                                                                                         printf("%d", b);
                                                                                     }else{
                                                                                         if ((d>c) && (c>a) && (a>b)){
                                                                                             
                       //return("The second largest number is ");
                                                                                             printf("%d", c);
                                                                                         }else{
                                                                                             if ((d>c) && (c>b) && (b>a)){
                                                                                                 
                           //return("The second largest number is ");
                                                                                                 printf("%d", c);
                                                                                             }
                                                                                         }
                                                                                     }
                                                                                 }
                                                                             }
                                                                         }
                                                                     }
                                                                 }
                                                             }
                                                         }
                                                     }
                                                 }
                                             }
                                         }
                                     }
                                 }
                             }
                         }
                     }
                }
            }
        }
    }
    }   
    //return 0;
}
