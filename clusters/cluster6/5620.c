int digitSum(int n)
{
	//Write solution here
	int temp = n, sum = 0, fsum = 0;;
	while(temp != 0)
	{
		sum += (temp % 10);
		temp /= 10;
	}

	if(sum < 10)
		return sum;
	else
		return(digitSum(sum));

}
