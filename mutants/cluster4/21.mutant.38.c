
int digitSum(int n)
{
	//Write solution here
	int tmp;
	while(n>10){
		tmp = n;
		n = 0;
		if(tmp){
			n += tmp%10;
			tmp/=10;
		}
	}
	return n;
}

