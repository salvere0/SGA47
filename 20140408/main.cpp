#include <iostream>
#include <conio.h>
#include "test.h"

using namespace std;

// template test
// 템플릿 테스트.
int main(void)
{
	// generic programming...

	Rect<int> a;
	Rect<int*> b;

	int* pa = new int(3);

	b.lt.x = pa;


	delete b.lt.x;


	_getch();
	return 0;
}
