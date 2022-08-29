int digitSum(int n)
{
	int sum;
	sum=0;
	while(n > 0 || sum >= 10 ){
            if(n == 1){
            n = sum;
            sum = 0;}
         
        sum = sum + n % 10;
        n = n/ 10;}
        printf("sum is %d ", sum);
	return 0;
}//Write solution here
