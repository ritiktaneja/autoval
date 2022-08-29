/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{ int n1,n2,n3,n4;
scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
 if(n1>n2 && n2>n3 && n3>n4){/* trying all permutatons in inequality */
   return("The second largest number is %d",n2);
} else if(n1>n2 && n2<n3 && n3>n4){
   if(n1>n3)
   return("The second largest number is %d",n3);
   else
   return("The second largest number is %d",n1);
} else if(n1>n2 && n2<n3 && n3<n4){
   if(n1>n4)
   return("The second largest number is %d",n4);
   else
   return("The second largest number is %d",n1);
}else if(n1<n2 && n2>n3 && n3>n4){
   if(n1>n3)
   return("The second largest number is %d",n1);
   else
   return("The second largest number is %d",n3);
}else if(n1<n2 && n2<n3 && n3>n4){
   if(n2>n4)
   return("The second largest number is %d",n2);
   else
   return("The second largest number is %d",n4);
}
  else if(n1<n2 && n2<n3 && n3<n4){
   return("The second largest number is %d",n3);}
else if(n1==n2 && n2==n3 && n3==n4 && n4==n1){/*trying all permutation in equality*/
   return("The second largest number is %d",n1);}
   else if(n1==n2 && n2==n3 && n3<n4 && n4>n1){
   return("The second largest number is %d",n1);}
   else if(n1==n2 && n2==n3 && n3>n4 && n4<n1){
   return("The second largest number is %d",n4);}
   else if(n1==n2 && n2<n3 && n3>n4 && n4==n1){
   return("The second largest number is %d",n4);}
   else if(n1>n2 && n2<n3 && n3==n4 && n4==n1){
   return("The second largest number is %d",n2);}
   else if(n1<n2 && n2>n3 && n3==n4 && n4==n1){
   return("The second largest number is %d",n3);}
   else if(n1>n2 && n2==n3 && n3==n4 && n4<n1){
   return("The second largest number is %d",n4);}
   else if(n1<n2 && n2==n3 && n3==n4 && n4>n1){
   return("The second largest number is %d",n1);}
   else if(n1==n2 && n2>n3 && n3==n4 && n4>n1){
   return("The second largest number is %d",n3);}
    else if(n1==n2 && n2<n3 && n3==n4 && n4<n1){
   return("The second largest number is %d",n2);}
    else if(n1>n2 && n2==n3 && n3<n4 && n4==n1){
   return("The second largest number is %d",n2);}
   else if(n1<n2 && n2==n3 && n3>n4 && n4==n1){
   return("The second largest number is %d",n1);}
   else if(n1==n3 && n2==n4 && n2>n3 ){
   return("The second largest number is %d",n3);}
   else if(n1==n3 && n2==n4 && n2<n3 ){
   return("The second largest number is %d",n2);}
   else if(n1==n2 && n2>n3 && n3>n4 ){
   return("The second largest number is %d",n3);}
    else if(n1==n2 && n2>n3 && n3<n4 ){
   return("The second largest number is %d",n3);}
    else if(n1==n2 && n2<n3 && n3>n4 ){
   return("The second largest number is %d",n2);}
    else if(n1==n2 && n2<n3 && n3<n4 ){
   return("The second largest number is %d",n2);}
 else if(n1==n3 && n3>n2 && n2>n4 ){
   return("The second largest number is %d",n2);}
    else if(n1==n3 && n3>n2 && n2<n4 ){
   return("The second largest number is %d",n2);}
    else if(n1==n3 && n3<n2 && n2>n4 ){
   return("The second largest number is %d",n3);}
    else if(n1==n3 && n3<n2 && n2<n4 ){
   return("The second largest number is %d",n3);}
   else if(n1==n4 && n4>n3 && n3>n2 ){
   return("The second largest number is %d",n3);}
    else if(n1==n4 && n4>n3 && n3<n2 ){
   return("The second largest number is %d",n3);}
    else if(n1==n4 && n4<n3 && n3>n2 ){
   return("The second largest number is %d",n4);}
    else if(n1==n4 && n4<n3 && n3<n2 ){
   return("The second largest number is %d",n4);}
   else if(n4==n3 && n3>n2 && n2>n1 ){
   return("The second largest number is %d",n2);}
    else if(n4==n3 && n3>n2 && n2<n1 ){
   return("The second largest number is %d",n2);}
    else if(n4==n3 && n3<n2 && n2>n1 ){
   return("The second largest number is %d",n3);}
    else if(n4==n3 && n1<n2 && n2<n1 ){
   return("The second largest number is %d",n3);}
   else if(n1>n2 && n2==n3 && n3>n4 ){
   return("The second largest number is %d",n2);}
    else if(n1>n2 && n2==n3 && n3<n4 ){
        if(n1>n4){
   return("The second largest number is %d",n4);}
   else
   return("The second largest number is %d",n1);}
    else if(n1<n2 && n2==n3 && n3>n4 ){
        if(n1>n4){
   return("The second largest number is %d",n1);}
   else
   return("The second largest number is %d",n4);}
    else if(n1<n2 && n2==n3 && n3<n4 ){
   return("The second largest number is %d",n2);}
   else if(n2==n4 && n1>n2 && n3>n4){
       if(n1>n3){
   return("The second largest number is %d",n3);}
   else
   return("The second largest number is %d",n1);
   }
   else if((n2==n4)&&(n1<n2)&&(n3>n4)){
 return("The second largest number is %d",n2);
   }
   else if(n2==n4 && n1<n2 && n3<n4){
 return("The second largest number is %d",n3);
   }
   else if(n2==n4 && n1>n2 && n3<n4){
 return("The second largest number is %d",n2);
   }
//return 0;
}