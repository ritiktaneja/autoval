int digitSum(int n)
{
	//Write solution here
	int sum = 0;
	int cond = 1;

   
		if(n > 0 || sum > 9){
			cond = 0;
			
		}
        if(1){
            n = sum;
            sum = 0;
        }

        sum += (n % 10);
        n /= 10;
    
	return sum;
}
