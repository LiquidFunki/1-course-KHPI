#include <stdio.h>

int main(){
  int a = 4;
  int b = 8;
  int result = 1;
    for(int i = 1; i < a; i++){
      if (a % i == 0 && b % i == 0){
          result = i;
      }
    }
  printf("%d", result) ;
  return 0;
}
