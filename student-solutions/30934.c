int digitSum(int n){
	//Write solution here

	int ans = 0;
	if(n < 10){
		return n;
	}

	while(n > 0){
		ans += n%10;
		n /= 10;
	}

	return digitSum(ans);
}

int main(){
	printf(digitSum(3));
}