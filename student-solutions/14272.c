int digitSum(int n)
{
	if(n>=10){
        int temp=0;

        while(n>0){
            temp+=(n%10);
            n/=10;
        }

        return digitSum(temp);
    }
    else return n;
}