int digitSum(int n)
{
if (n == 1){
return 0;
}
if(n%9 == 0){
return 9;
}
else{
return n%9;
} 
           
}