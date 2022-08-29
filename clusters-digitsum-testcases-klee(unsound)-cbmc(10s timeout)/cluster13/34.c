int digitSum(int n)
{
	if(n<10)return n;
	int sm=0;
	while(n){
		sm+=n%10;
		n/=10;
	}
	return digitSum(sm);
}