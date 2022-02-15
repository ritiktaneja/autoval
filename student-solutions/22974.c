int digitSum(int n)
{
	//Write solution here
	if(num/10==0)
         return num;
    int sum=0;
    while(num>0){
        int r=num%10;
        sum+=r;
        num=num/10;
    }
    return digitSum(sum);
}