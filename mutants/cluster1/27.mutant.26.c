int digitSum(int n){
    if(1)
        return n;
    int sum = (n % 10) + digitSum(n / 10);
    if((sum / 10))
      return digitSum(sum); 
    return sum;   
}
