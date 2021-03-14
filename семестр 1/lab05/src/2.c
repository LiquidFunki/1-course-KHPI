#include <stdbool.h>
#include <stdio.h>
#include <math.h>
int main(){
  int a = 13;
  char ans;
  bool flag = true;
      if ( a == 1 ){
      ans = 'n';
      }
      else{
      int sqrt_copy = sqrt(a) + 1;
      for (int i = 2; i < sqrt_copy; i++ )
          if ( a % i == 0){
            flag = false;
            break;
          }
      }
    if (flag){
      ans = 'y';
    }
    else{
      ans = 'n';
    }
    printf("%c", ans);
    return 0;
}
