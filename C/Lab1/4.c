#include <stdio.h>

int main(){
  int res = 1;
  printf("0 ");
  while(res < 10000){
    printf("%d ",res);
    res *= 2;
  }
  return 0;
}
