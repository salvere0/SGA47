#include <iostream>
#include <conio.h>
#include "doublelinkedlist.h"

using namespace std;

enum key_id
{
	SPECIAL	= 0xE0,
	UP		= 0x48,
	DOWN	= 0x50,
};

struct ItemInfo
{
	ItemInfo()
		:price(0)
	{
		name[0] = '\0';
	}
	int price;
	char name[20];

	friend istream& operator >> (istream& is, ItemInfo& obj)
	{
		cout << "name : ";
		is >> obj.name;
		cout << "price : ";
		is >> obj.price;
		return is;
	}
	friend ostream& operator << (ostream& os, const ItemInfo& obj)
	{
		os << obj.name << ", " << obj.price;
		return os;
	}
};

int main(void)
{


	LinkedList<ItemInfo*> test;

	while (true)
	{
		// input
		if (_kbhit())
		{
			int key = _getch();
			if (key == '+')
			{
				LinkedList<ItemInfo*>::value_type data = new ItemInfo;
				cin >> *data;
				test.insert(data);
			}
			else if (key == '-')
			{
				test.remove();
			}
			else if (key == SPECIAL)
			{
				key = _getch();
				if (key == UP) // up arrrow
					test.prev();
				else if (key == DOWN) // down arrow
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
