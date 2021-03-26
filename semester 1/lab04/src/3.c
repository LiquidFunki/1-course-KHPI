int main(){
    int k = 5;
    int m = -1;
    int n = 3;
    int x = 0;
        if (k>=m){
            x = k;
            k = m;
            m = x;
        }
        else if (k>=n){
            x = k;
            k = n;
            n = x;
        }
        if (m>=n){
            x = m;
            m = n;
            n = x;
        }
printf("%d %d %d", k, m, n);
return 0;
}
