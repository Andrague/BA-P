#include<iostream>
#include <math.h>
#include <conio.h>
using namespace std;
int main(int argc, char* argv[])
{
	double x, z, n, k, m, rez, funct;
	int key;
	cout<<'\n'<<"z n k m = (vvod bez zpt cherez probel)";
	cin >> z >>  n >>  k >>  m;
	cout << "Vi vveli:" << z << n << k << m;
	if (z > 1) x = z;
	else if (z <= 1)x = ((z * z) + 1);
	cout << '\n' << "Pri z=" << z <<'\n' << "x=" << x;
	
	do {
		cout << "\n Vvedite 1, esli hotite vibrat 2x, 2 - esli x ^ 2, 3 - esli x / 3 : ";
		cin >> key;
	} while (key<1 || key>3);
			switch (key) {
				case 1: funct = 2 * x; break;
				case 2: funct = pow(x, 2); break;
				case 3: funct = x / 3.0; break;
				
			} 
		
	rez = sin(n *funct) + cos(k * x) + log10(m * x);
	cout << "\n Rezultat vichisleniy: " << rez <<" \n";
		return 0;
}
