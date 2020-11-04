int main(){
    float x = -3;
    float y;
    if ( x <= -1){
        y = -1.0/x;
    }
    else if ( x > -1 && x <= 1){
        y = x * x;
    }
    else if ( x > 1 && x <= 2){
        y = 1.0;
    }
    printf("%.2f", y);
    return 0;
}
