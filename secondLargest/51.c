/*compile-errors:e156_271608.c:4:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
student_solution(int input_a, int input_b, int input_c, int input_d)
^~~~
1 warning generated.*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;


int student_solution(int input_a, int input_b, int input_c, int input_d)
{
	int a,b,c,d;

	scanf("%d%d%d",&a,&b,&c,&d);


	int atemp1 = b-a;
	int atemp2 = c-a;
	int atemp3 = d-a;

	int btemp1 = a-b;
	int btemp2 = c-b;
	int btemp3 = d-b;

	int ctemp1 = a-c;
	int ctemp2 = b-c;
	int ctemp3 = d-c;

	int dtemp1 = a-d;
	int dtemp2 = b-d;
	int dtemp3 = c-d;
		
	if( (atemp1 < 1  & atemp2 < 1  & atemp3 > 0) | (atemp1 < 1 & atemp2 > 0 & atemp3 < 1) |(atemp1 > 0 & atemp2 < 1 & atemp3 < 1) )
	{
		return("The second largest number is %d\n",a);
	}
	
	else if( (btemp1 < 1 & btemp2 < 1 & btemp3 > 0) | (btemp1 < 1 & btemp2 > 0 & btemp3 < 1) |(btemp1 > 0 & btemp2 < 1 & btemp3 < 1) )
	{
		return("The second largest number is %d\n",b);
	}

	else if( (ctemp1 < 1 & ctemp2 < 1 & ctemp3 > 0) | (ctemp1 < 1 & ctemp2 > 0 & ctemp3 < 1) |(ctemp1 > 0 & ctemp2 < 1 & ctemp3 < 1) )
	{
		return("The second largest number is %d\n",c);
	}

	else if( (dtemp1 < 1 & dtemp2 < 1 & dtemp3 > 0) | (dtemp1 < 1 & dtemp2 > 0 & dtemp3 < 1) |(dtemp1 > 0 & dtemp2 < 1 & dtemp3 < 1) )
	{
		return("The second largest number is %d\n",d);
	}
	

}

