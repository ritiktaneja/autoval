int digitSum(int n)
{
	//Write solution here

	int sum_of_digits;
	sum_of_digits = 0;
	int temp; 
	temp = n;
	int final;
	final = n;
	
	while (temp != 0){

		sum_of_digits = 0;
		final = temp;

		while (n != 0){
		sum_of_digits = sum_of_digits + n % 10;
		n = n/10;
		}

		temp = sum_of_digits;

	}

return final;

}