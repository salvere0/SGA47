#include <iostream>
#include <conio.h>

using namespace std;

template<int n>
struct factorial
{
	enum { value = n * factorial<n-1>::value};
};

template<>
struct factorial<1>
{
	enum {value = 1};
};

int main(void)
{
	cout << factorial<5>::value << endl;

	_getch();
	return 0;
}
