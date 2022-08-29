/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    if(a>b){        //checking whether a is 2nd largest
        if((a>c && a<d) || (a<c && a>d)){
            if(!((a>=b) && (a>=c) && (a>=d))){
            return("The second largest number is %d",a);
            }
        }
    }else{
        if(a>c && a>d){
        return("The second largest number is %d",a);
        }
    }
    
     if(b>c){       //checking whether b is 2nd largest
        if((b>d && b<a) || (b<d && b>a)){
             if(!((b>=a) && (b>=c) && (b>=d))){
            return("The second largest number is %d",b);
             }
        }
    }else{
        if(b>=d && b>=a){
        return("The second largest number is %d",b);
        }
    }
    
     if(c>d){       //checking whether c is 2nd largest
        if((c>a && c<b) || (c<a && c>b)){
             if(!((c>=b) && (c>=a) && (c>=d))){
            return("The second largest number is %d",c);
             }
        }
    }else{
        if(c>=a && c>=b){
        return("The second largest number is %d",c);
        }
    }
    
     if(d>a){       //checking whether d is 2nd largest
        if((d>b && d<c) || (d<b && d>c)){
             if(!((d>=b) && (d>=c) && (d>=a))){
            return("The second largest number is %d",d);
             }
        }
    }else{
        if(d>b && d>c){
        return("The second largest number is %d",d);
        }
    }
    // Fill this area with your code.
    //return 0;
}