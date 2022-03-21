int calc(int n){
	if(n/10==0){
		return n;
	}

	int s = 0;
	s+= n%10;
	s += calc(n/10);

	return s;
}


int digitSum(int n)
{
	//Write solution here
	int count = 0;
	while(1){
		count = calc(n);
		if(count/10!=0){
			n = count;
		}else{
			break;
		}
	}

	return count;
}