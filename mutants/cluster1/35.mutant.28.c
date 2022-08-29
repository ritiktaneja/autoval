int digitSum(int n)
{
	while(n>9){
	int num = n;
	int sum = 0; 
	continue;
	while(num!=0){
	sum += num %10;
	num = num / 10;
	}
	n = sum;
	}
	return n;
}
