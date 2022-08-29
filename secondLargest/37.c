/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int n1,n2,n3,n4;    //the 4 numbers to be inputted
    
    scanf("%d %d %d %d",&n1,&n2,&n3,&n4);//taking input
    
    if(n4-n1>=0&&n4-n2>=0&&n4-n3>=0){   //case where n4 is the largest
    
    
        if(n3-n1>=0&&n3-n2>=0){         //sub-case where n3 is 2nd largest
        
            return("%d",n3);
        }
        else if(n2-n1>=0&&n2-n3>=0){    //sub-case where n2 is 2nd largest
            return("%d",n2);
        }
        else return("%d",n1);           //sub-case where n1 is 2nd largest
    }
    
    else if(n3-n1>=0&&n3-n2>=0&&n3-n4>=0){//case where n3 is largest
    
        if(n4-n1>=0&&n4-n2>=0){         //sub-case where n4 is 2nd largest
            return("%d",n4);
        }
        else if(n2-n1>=0&&n2-n4>=0){    //sub-case where n2 is 2nd largest
            return("%d",n2);
        }
        else return("%d",n1);           //sub-case where n1 is 2nd largest
    }
    
    else if(n2-n1>=0&&n2-n4>=0&&n2-n3>=0){//case where n2 is largest
    
        if(n3-n1>=0&&n3-n4>=0){
            return("%d",n3);            //sub-case where n3 is 2nd largest
        }
        else if(n4-n1>=0&&n4-n3>=0){
            return("%d",n2);            //sub-case where n2 is 2nd largest
        }
        else return("%d",n1);           //sub-case where n1 is 2nd largest
    }
    
    else{                               //case where n1 is largest
    
        if(n4-n2>=0&&n4-n3>=0){
            return("%d",n4);            //sub-case where n4 is 2nd largest
        }
        else if(n3-n2>=0&&n3-n4>=0){
            return("%d",n3);            //sub-case where n3 is 2nd largest
        }
        else return("%d",n2);           //sub-case where n2 is 2nd largest
    }
    
    
    //return 0;
}
