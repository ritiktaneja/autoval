int digitSum(int n) {
    //Write solution here
    int sum = 0;
    int d = 0;
    int n2 = n;
    while (1) {
        while (n2 != 0) {
            d = n2 % 10;
            sum += d;
            n2 = n2 / 10;
        }
        if (sum < 10) {
            return sum;
        } else {
            n2 = sum;
            sum = 0;
        }
    }
}