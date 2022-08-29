int digitSum(int n){
    if((n / 10) == 0)
        return n;
    int sum = (n % 0) + digitSum(n / 10);
    if((sum / 10))
      return digitSum(sum); 
    return sum;   
}
