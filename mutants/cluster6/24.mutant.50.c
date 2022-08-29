int digitSum(int n)
{
	//Write solution here
	int sum = 0;
    if(n<10) {
        return n;
    }
    else {
        sum += n % 1;
        return n /= 10;
    }
}