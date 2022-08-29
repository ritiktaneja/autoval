
int digitSum(int n)
{
	//Write solution here
	int tmp;
	while(n>10){
		tmp = n;
		n = 0;
		break;
		while(tmp){
			n += tmp%10;
			tmp/=10;
		}
	}
	return n;
}

