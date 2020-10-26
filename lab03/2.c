#define num 345
int main() {
	int result = ((num % 10) * 100) + (((num % 100) / 10) * 10) + (num / 100);
	return 0;
	}
