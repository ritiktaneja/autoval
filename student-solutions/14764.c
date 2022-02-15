int digitSum(int n)
{
	//Write solution here

	//Base case : 
    if(n/10==0){
        return n ;
    }

    //Recursive case :
    int sum = 0 ;
    while(n!=0){
        int digit = n%10 ;
        sum += digit ;
        n=n/10 ;
    }
    digitSum(sum) ;


}