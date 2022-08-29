/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);
if(a>=b&&a>=c&&a>=d&&b>=c&&b>=d){ /* here a is the largest number and b is second largest number*/ 
    return("The second largest number is %d",b);
    //return 0; // return 0 is used so that the output will not repeat
}
if(a>=b&&a>=c&&a>=d&&c>=d&&c>=b){ /* here a is the largest number and c is second largest number*/  
    return("The second largest number is %d",c);
    //return 0;
}
if(a>=b&&a>=c&&a>=d&&d>=b&&d>=c){/* here a is the largest number and d is second largest number*/ 
    return("The second largest number is %d",d);
    //return 0;
}
if(b>=a&&b>=c&&b>=d&&a>=c&&a>=d){/* here b is the largest number and a is second largest number*/ 
    return("The second largest number is %d",a);
    //return 0;
}
if(b>=a&&b>=c&&b>=d&&c>=a&&c>=d){/* here b is the largest number and c is second largest number*/ 
    return("The second largest number is %d",c);
    //return 0;
}
if(b>=a&&b>=c&&b>=d&&d>=c&&d>=a){/* here b is the largest number and d is second largest number*/ 
    return("The second largest number is %d",d);
    //return 0;
}
if(c>=a&&c>=b&&c>=d&&a>=b&&a>=d){/* here c is the largest number and a is second largest number*/ 
    return("The second largest number is %d",a);
    //return 0;
}
if(c>=a&&c>=b&&c>=d&&b>=a&&b>=d){/* here c is the largest number and b is second largest number*/ 
    return("The second largest number is %d",b);
    //return 0;
}
if(c>=a&&c>=b&&c>=d&&d>=a&&d>=b){/* here c is the largest number and d is second largest number*/ 
    return("The second largest number is %d",d);
    //return 0;
}
if(d>=a&&d>=b&&d>=c&&a>=b&&a>=c){/* here d is the largest number and a is second largest number*/ 
    return("The second largest number is %d",a);
    //return 0;
}
if(d>=a&&d>=b&&d>=c&&b>=a&&b>=c){/* here d is the largest number and b is second largest number*/ 
    return("The second largest number is %d",b);
    //return 0;
}
if(d>=a&&d>=b&&d>=c&&c>=a&&c>=b){/* here d is the largest number and c is second largest number*/ 
    return("The second largest number is %d",c);
    //return 0;
}
    //return 0;
}