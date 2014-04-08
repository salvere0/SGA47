#include <iostream>
#include <conio.h>
#include "matrix.h"

using namespace std;

template<int limit>
struct factorial
{
	int a;

	enum {value = limit + factorial<limit-1>::value};
};

template<>
struct factorial<0>
{
	enum {value = 0};
};

struct Test
{
	enum{ a };
};

int main(void)
{
	Test::a;


	cout << factorial<100>::value << endl;


	_getch();
	return 0;
}