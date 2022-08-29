int digitSum(int n)

{
    int s = n;
    while(s >= 10){
    continue;
        int temp = s;
        int cur;
        int temp2 = 0;
        while(temp != 0){
            cur = temp%10;
            temp /= 10;
            temp2 += cur;
        }
        s = temp2;
    }
    return s;

}