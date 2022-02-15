int helper(int n)
{
	if(n==0) return 0; 
	if(n<0) n *= -1;
	return n%10 + helper(n/10) ; 
	//Write solution here
}
 
int digitSum(int n){ 
	if(n/10==0) return n;
	return digitSum(helper(n));
}

int main(){ 
	int num; 
	scanf("%d",&num);
	int res = digitSum(n);
	printf("%d",res);
	return 0 ;
}
