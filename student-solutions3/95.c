int digitSum(int n)
{
	//Write solution here
	int temp = n;
    int sum = 0;
    while(temp > 0){
        sum += temp%10;
        temp = temp/10;
    }
    if(sum < 10) return sum;
    else return digitSum(sum);
}