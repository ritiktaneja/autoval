/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{

   int y;y = input_year;;
   
   //scanf("%d",&y); //stores the year
   
 {  if(y%4==0) //divisiblity by 4
   
    {   if(y%100==0)   //divisiblity by 100
        
          {if(y%400==0)    //divisiblity by 400
        
          return 1;
        
          else return 0;}
        
       else return 1;   }
    
    else return 0;  }
       
       
       
       //return 0;
}