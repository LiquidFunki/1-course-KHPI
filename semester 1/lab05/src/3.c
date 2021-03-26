#include <stdio.h>
#include <stdbool.h>
int main(){
  int n = 235622;
  char ans;
  bool flag = false;
  int sum1 = n / 100000 + (n / 10000) % 10 + (n / 1000) % 10;
  int sum2 = (n / 100) % 10 + (n / 10) % 10 + n % 10;
    if ( sum1 == sum2 ){
      flag = true;
    }
    if (flag){
      ans = 'Y';
    }
    else{
      ans = 'N';
    }
  printf("%c", ans);
  return 0;
}



// n / 100000 = 1st number
// (n / 10000) % 10 = 2nd number
// (n / 1000) % 10 = 3rd number
// (n / 100) % 10 = 4th number
// (n / 10) % 10 = 5th number
// n % 10 = 6th number
