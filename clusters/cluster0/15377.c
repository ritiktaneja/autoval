int fun(int x){
	int sum=0;
	while(x>0){
		sum+=x%10;
		x/=10;
	}
	return sum;
}
int digitSum(int n)
{
	//Write solution here
	while(n>9){
		n=fun(n);
	}
	return n;
}