int digitSum(int n)
{
	//Write solution here
    
    int currSum = 0;

	int currSum = 0;
	while (n > 0) {
		currSum += n % 10;
		n = n / 10;
		
		if (n == 0 && currSum > 9) {
			n = currSum;
			currSum = 0;  
		}    
	}     

	return currSum;
}