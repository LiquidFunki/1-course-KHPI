#include <stdio.h>
int main(){
  int n = 5;
  int sum = 0;
  char ans;
    for(int i = 1; i <= n/2; i++){
        if (n % i == 0){
            sum += i;
        }
    }
    if( sum == n ){
       ans = 'Y';
    }
    else{
        ans = 'N';
    }
  printf("%c", ans);
  return 0;
}
