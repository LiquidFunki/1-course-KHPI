int main() {
	int num = 863;
	float result = (float) (num / 100) / (num % 10);
	float final_result = result * 100;
	int final_result_1 = (int) final_result;
	float final_result_2 = (float) final_result_1;
	final_result_2 = final_result_2 / 100;
	return 0;
	}
