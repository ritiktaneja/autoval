int digitSum(int n)
{
	//Write solution here
	int sum = -1;
    if(n<10) {
        return n;
    }
    else {
        sum += n % 10;
        return n /= 10;
    }
}