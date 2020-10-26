#define R1 24.0
#define R2 24.0
#define R3 6.0
int main()
	{
	float R = (R1 * R2 * R3)/(R2 * R3 + R1 * R3 + R1 * R2);
	printf("%.f", R);
	return 0;
	}
