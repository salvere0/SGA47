#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "MyStack.h"
#include "MyQueue.h"

using namespace std;

int main(void)
{
	MyQueue<int> test;

	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == '+')
			{
				int input;
				cout << "int : ";
				cin >> input;

				test.push(input);
			}
			else if (key == '-')
			{
				test.pop();
			}
			else if (key == 0x1B)
			{
				break;
			}
		}

		system("cls");
		if (!test.IsEmpty())
			cout << test.value() << endl;
		cout << "==================" << endl;
	}

	_getch();
	return 0;
}
