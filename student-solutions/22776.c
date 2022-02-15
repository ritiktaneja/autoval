int digitSum(int n){
    if(n < 10){
        return n;
    }
    
	int sum = 0;
	while(n){
	    sum += n % 10;
	    n /= 10;
	}
	return digitSum(sum);
}

