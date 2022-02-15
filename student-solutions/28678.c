int digitSum(int n)
{
	//Write solution here	
	if(n<10) {
		return n;
	}

	int sumOfdigits=0;
	int temp;
	while(n!=0) {
		temp=n%10;
		sumOfdigits=sumOfdigits+temp;
		n=n/10;
	}
	return digitSum(sumOfdigits);

}