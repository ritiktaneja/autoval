int digitSum(int n)
{
	int x=0,val;

	for (int i=0;i<n ; i+1){
		if(n==0){
			break;
		}
		val=n%10;
		x=x+val;
		n=n/10;
	}

	return x;
}