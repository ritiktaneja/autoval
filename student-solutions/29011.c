int digitSum(int n){
    int ret=0;
    while(n != 0){
        ret += n%10;
        n /= 10;
    }
    if(ret/10 != 0){
        ret = getsum(ret);
    }
    return ret;
}