int main() {
	int num = 1234;
	int p = 8;
	int result = 1 * (num % 10) + p * ((num % 100) / 10) + p * p * ((num % 1000) / 100) + p * p * p * (num / 1000);
	return 0;
	}
