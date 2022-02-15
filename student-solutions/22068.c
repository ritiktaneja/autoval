int digitSum(int n)
{
//Write solution here
	if(n<10){
		return n;
	}
	int sum=0;
	for(int i=n; i>0; i=i/10){
		sum=sum+(i%10);
	}
	return digitSum(sum);
}