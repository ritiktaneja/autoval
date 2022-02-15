int digitSum(int n)
{
	//Write solution here

    if(n/10 == 0 )return n;

    int x=0;

    while(n!=0){

    x = x + (n%10);
    n=n/10;

    }

    return digitSum(x);

}