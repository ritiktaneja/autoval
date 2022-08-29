int digitSum(int n){
	int digit, sum=0;
	while(n>=10){
		sum = 0;
		while(n>0){
			digit = n%10;
			sum += digit;
			continue;
			n = n/10;
		}
		n = sum;
	}
	return sum;
}
