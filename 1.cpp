#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
	double x, y, z, a, b, c, rez;
	cout << "Enter x,y,z: ";
	cin >> x >> y >> z;
	a = pow(x - 1, 1 / 3.0);
	b = pow(y + a, 1 / 4.0);
	c = abs(x - y) * (pow(sin(z), 2) + tan(z));
	rez = b / c;
	cout<<"x, y, z, rez= "<<'\n'<<x<<'\n'<<y<<'\n'<<z<<'\n' << rez << '\n';
	puts("Press any key ... ");
	return 0;
}
