/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int  y;y = input_year;;/*year to be considerd*/
    //scanf("%d",&y);
    if (y%100==0)
           {if (y%400==0)
              {return 1;}
                
    else
                {return 0;}
           
           }
    else
        
           {if (y%4==0)
              {return 1;}
        else
               {return 0;}
           }
        
        //return 0;
        }