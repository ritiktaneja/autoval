#include<assert.h>
#include<stdio.h>
int get_sign(int x,int y) {
 
  if(x==0)
    return 0;
  else if(x>0)
    return 2;
  return -2;

}
