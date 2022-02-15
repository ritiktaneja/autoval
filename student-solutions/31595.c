int digitSum(int n)
{
	//Write solution here
	
	if(n/10 < 1){
	    return n;
	}else{
	    
	    if(n%10+ digitSum(n/10) > 9){
	       return digitSum(n%10+ digitSum(n/10));
	    }else{
	        return n%10+ digitSum(n/10);
	    }
	}
}
