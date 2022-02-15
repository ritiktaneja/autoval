int digitSum(int n)
{
	//Write solution here
	int a=0;
	while(n>=10){
		a = 0;
		while(n){
			a += n%10;
			n/=10;
		}
		n = a;
	}

	return n;
}