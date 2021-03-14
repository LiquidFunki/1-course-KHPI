int main() {
double first_a = 2;
double a, b, c, d, h;

a = first_a;
a = a * a;//a^2
a = a * a;//a^4

a = first_a;
a *= a;//a^2
a *= a;//a^4
a *= a;//a^8

a = first_a;
a *= a;//a^2
b = a * a;//a^4
a *= b;//a^6

a = first_a;
c = a * a;//a^2
d = c * c;//a^4
h = d * c;//a^6
a = h * d;//a^10

return 0;
}

