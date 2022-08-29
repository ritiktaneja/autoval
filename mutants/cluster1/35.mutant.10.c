int digitSum(int n)
{
	while(n>0){
	int num = n;
	int sum = 0; 
	while(num!=0){
	sum += num %10;
	num = num / 10;
	}
	n = sum;
	}
	return n;
}
