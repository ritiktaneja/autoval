int digitSum(int n)
{
	int temp = 0;

	while(temp>9 || n>0){

        if(n==0){
            n = temp;
            temp = 0;

        }
        temp = temp+(n%10);
        n /=10;
	}

	return temp;
}
