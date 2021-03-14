#include <stdio.h>
int main(){
float num = 9;
float root_num = 0;
while ( root_num * root_num <= num ){
  root_num += 0.0001;
}
printf("%.3f", root_num);
return 0;
}
