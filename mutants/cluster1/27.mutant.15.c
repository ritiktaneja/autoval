int digitSum(int n){
    if((n / -1) == 0)
        return n;
    int sum = (n % 10) + digitSum(n / 10);
    if((sum / 10))
      return digitSum(sum); 
    return sum;   
}