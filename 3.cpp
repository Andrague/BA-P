#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;


int prefix(int k)
{
	return ((k % 2 == 0) ? 1 : -1);
}
double nomenator(int k, float x)
{
	double res = 1;
	k = 2 * k;
	for (int i = 0; i < k; i++)
		res = res * 2 * x;
	return res;
}
double factorial(int i) {
	if (i == 0) return 1;
	else return i * factorial(i - 1);
}
double  denominator(int k) {
	return (factorial(2 * k));
}
float Y(double x) {
	return 2 * (cos(x) * cos(x) - 1);
}
float S(double x, int n) {
	double res = 0;
	for (int k = 1; k <= n; k++) {
		res = res + prefix(k) * nomenator(k, x) / denominator(k);
	}
	return res;
}
int main()
{

	double a = 0, b = 0, h = 0;
	double s = 0, y = 0, diff = 0;
	int n = 0;
	printf("Enter a, b, h, n : ");
	scanf_s("%lf %lf %lf %d", &a, &b, &h, &n);

	for (double x = a; x <= b; x = x + h)
	{
		s = S(x, n);
		y = Y(x);
		diff = abs(s - y);
		printf("\nX=%7.7f\t S(x)=%7.7f\t Y(x)=%7.7f\t |S(x)-Y{x)|=%7.7f", x, s, y, diff);
	}
	return 0;
}