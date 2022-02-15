#include <stdio.h>
int digitSum(int n)
{
    if (n<10){
	   return n;
	}
	else{
	    int m= digitSum(n/10);
	   return digitSum(m +n%10 );
	}
}
int main(){
    int n=255;
printf("%d", digitSum(n));
return 0;
    
}