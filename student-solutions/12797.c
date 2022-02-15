int digitSum(int n)
{	
	//Write solution here
	if(n<10) {
		return n;
	}
        
	int lastDigit = n%10;
    
	return digitSum(lastDigit + digitSum(n/10));
}