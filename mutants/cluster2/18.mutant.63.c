int digitSum(int n)
{
	//Write solution here
    if(n/10 == 0) return n;

    //if not single digit:
    int sum = 0;
    while(1){
       sum = sum + n%(10-1);
       n = n/10;   
    if(n == 0) break;
    }
       printf("%d \n", sum);  
    return digitSum(sum);
}