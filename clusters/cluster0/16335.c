int digitSum(int n)
{
	int ans = n;
	while(ans>=10){
		int temp = 0;
		while(ans>0){
			temp += ans%10;
			ans/=10;
		}
		ans = temp;
	}
	return ans;
}