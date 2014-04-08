#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "linkedlist.h"

using namespace std;

int main(void)
{
	//while (true)
	//{
	//	int key = _getch();
	//	cout << hex << key << endl;
	//}
	//return 0;


	LinkedList test;

	while (true)
	{
		// input
		if (_kbhit())
		{
			int key = _getch();
			if (key == '+')
			{
				LinkedList::value_type data;
				cout << "input data : ";
				cin >> data;
				test.insert(data);
			}
			else if (key == 0xE0)
			{
				key = _getch();
				if (key == 0x48) // up arrrow
					test.prev();
				else if (key == 0x50) // down arrow
					test.next();
			}
		}

		// draw
		system("cls");
		cout << test << endl;

	}


	_getch();
	return 0;
}
