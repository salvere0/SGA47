#include <iostream>
#include <conio.h>
#include "matrix.h"

using namespace std;

int main(void)
{
	Matrix e;

	cout << e << endl;

	Matrix a(1,2,3,4);

	//cout << a << endl;

	//cout << e*a << endl;
	//cout << a*e << endl;
	//cout << a*2 << endl;
	//cout << 3*a << endl;
	//cout << (2*a) * (3*a) << endl;
	//cout << 2*a * 3*a << endl;
	//cout << (a<<2) << endl;
	//cout << (a<<3) << endl;
	//cout << a[0] << endl;
	//cout << a[1] << endl;
	//cout << a[2] << endl;
	//cout << a[3] << endl;

	cout << a << endl;

	a[0] = 3;

	cout << a << endl;

	a[-1] = 1;

	cout << a << endl;

	Matrix b;

	b = a = 5;

	cout << b << endl;
	cout << a << endl;

	_getch();
	return 0;
}
