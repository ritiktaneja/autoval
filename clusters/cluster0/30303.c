int digitSum(int n)
{
	if(n<10){
		return n;
	}
	int temp=0;
	while(n){
		temp+=(n%10);
		n/=10;
	}
	return digitSum(temp);
}