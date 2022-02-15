#include <stdio.h>
#define LAST 10


int digitSum(int n)
{
    //Write solution here

    int tempsum = 0;
	while (n != 0) {
    int r;
    r = n % 10;
    tempsum+=r;
        n = n / 10;
    }
    if(tempsum >= 10){
        return digitSum(tempsum);
    }
    else{
        return tempsum;
    }

}




void solve(int tc){
    int n;
    scanf("%d",&n);
    int sum = digitSum(n);
    printf("%d\n",sum);
}

      
int main()
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int tc;
    scanf("%d",&tc);

    for(int i = 0 ; i < tc;i++){
        solve(i);
    }

    return 0;
}