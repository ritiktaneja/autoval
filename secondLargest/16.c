/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d){
    int a,b,c,d,sl=0,l=0;   //Declaring variables
    scanf("%d %d %d %d",&a,&b,&c,&d);  //Taking Input
    
    /*Now in every if block ,its checked that input is largest or          second largest and stored accordingly in second largest(sl) or         largest (l)*/
   
   //4 if-else-if blocks are used due to 4 inputs
   
    if(a>=l){    //input is greater than largest number
        sl=l;    //2nd largest=largest
        l=a;     //Largest = Input(as its now largest)
    }else if(a>=sl){ //in case if l>input>sl
        sl=a;
    }
    
    
    if(b>=l){     //input is greater than largest number
        sl=l;     //2nd largest=largest
        l=b;      //Largest = Input(as its now largest)
    }else if(b>=sl){ //in case if l>input>sl
        sl=b;
    }
    
    
    if(c>=l){      //input is greater than largest number
        sl=l;      //2nd largest=largest
        l=c;       //Largest = Input(as its now largest)
    }else if(c>=sl){ //in case if l>input>sl
        sl=c;
    }
    
    
    if(d>=l){       //input is greater than largest number
        sl=l;       //2nd largest=largest
        l=d;        //Largest = Input(as its now largest)
    }else if(d>=sl){ //in case if l>input>sl
        sl=d;
    }
    
    /*Now when all inputs are checked sl will contain 2nd largest          number*/

    return("The second largest number is %d",sl);
    //return 0;
}