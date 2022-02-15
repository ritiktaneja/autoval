int digitSum(int n)
{
	if(n<10){
 return n;
}
int t=n;
int add=0;
for(t>0){
  add+=t%10;
  t=t/10;
}
return digitSum(add);
}
