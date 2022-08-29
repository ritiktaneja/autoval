/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    scanf ("%d%d%d%d",&a,&b,&c,&d);
    if (a>=b&&(b>=c&&b>=d)){
        return ("The second largest number is %d",b);
    }
    else if (a>=c&&(c>=b&&c>=d)){
        return ("The second largest number is %d",c);
    }
    else if (a>=d&&(d>=b&&d>=c)){
        return ("The second largest number is %d",d);
    }
    else if (b>=a&&(a>=c&&a>=d)){
        return ("The second largest number is %d",a);
    }
    else if (b>=c&&(c>=a&&c>=d)){
        return ("The second largest number is %d",c);
    }
    else if (b>=d&&(d>=a&&d>=c)){
        return ("The second largest number is %d",d);
    }
    else if (c>=a&&(a>=b&&a>=d)){
        return ("The second largest number is %d",a);
    }
    else if (c>=b&&(b>=a&&b>=d)){
        return ("The second largest number is %d",b);
    }
    else if (c>=d&&(d>=a&&d>=c)){
        return ("The second largest number is %d",d);
    }
    else if (d>=a&&(a>=b&&a>=c)){
        return ("The second largest number is %d",a);
    }
    else if (d>=b&&(b>=a&&b>=c)){
        return ("The second largest number is %d",b);
    }
    else if (d>=c&&(c>=a&&c>=b)){
        return ("The second largest number is %d",c);
    }
    //return 0;
}