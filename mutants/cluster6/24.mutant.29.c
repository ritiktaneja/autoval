int digitSum(int n)
{
	//Write solution here
	int sum = 0;
    if(0) {
        return n;
    }
    else {
        sum += n % 10;
        return n /= 10;
    }
}