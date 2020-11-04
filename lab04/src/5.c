int main(){
    int x = 0;
    int y = 0;
	if (x <=(-1)) {
		y = -x - 1;
		}
	if (x > (-1) && x <= 0) {
		y = x + 1;
		}
	if (x > 0 && x <= 1) {
		y = -x + 1;
		}
	if (x > 1 ){
		y = x - 1;
		}
    printf ("%d", y);
    return 0;
}
