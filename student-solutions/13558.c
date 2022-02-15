int digitSum(int n){
    if(n<10){
        //if single digit, sum of digits = the value
       return n; 
    }else{
		//call recursively
        return digitSum(digitSum(n/10) + (n%10));
    }
}