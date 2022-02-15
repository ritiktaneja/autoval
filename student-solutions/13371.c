int digitSum(int n){
	if(n<10) return n;
	int ans=0;
	while(n>0){
		ans+=n%10;
		n/=10;
	}
	return digitSum(ans);
}