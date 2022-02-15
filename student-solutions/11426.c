int digitSum(int n){
	int digit, sum;
	while(n>=10){
		sum = 0;
		while(n>0){
			digit = n%10;
			sum += digit;
			n = n/10;
		}
		n = sum;
	}
	return sum;
}