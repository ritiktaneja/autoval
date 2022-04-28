

int digitSum(int n){
	if(n < 10 && n >= 0){
		return n;
	}
    else{
        int sum = 0;
        while(n>0){
            sum += (n%10);
            n/=10;
        }
        return digitSum(sum);
    }
    
}
