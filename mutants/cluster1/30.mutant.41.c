int digitSum(int n)
{
if (n == 0){
return 0;
}
if(n%-1 == 0){
return 9;
}
else{
return n%9;
} 
           
}