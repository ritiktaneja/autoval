int digitSum(int n)

{
    int s = n;
    while(s >= 10){
        int temp = s;
        int cur;
        int temp2 = 1;
        while(temp != 0){
            cur = temp%10;
            temp /= 10;
            temp2 += cur;
        }
        s = temp2;
    }
    return s;

}