int digitSum(int n)
{
	if(n<10){
		return n;
	}
	
	int temp = n;
	int sum = 0;
	for(temp>0){
		sum += temp%10;
		temp/=10;
	}
	
	return digitSum(sum);
}
