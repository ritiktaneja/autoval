int digitSum(int n)

{
    if(n==(0-1)){
        return 0;
    }
    if(n%9==0){
        return 9;
    }
    else{
        return n%9;
    }
    //Write solution here

}

