#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "LinkedList.h";
using namespace std;

int main()
{
	char fileName[] = "data.bin";
	LinkedList* Head = NULL;
	int operation;
	while (true)
	{
		cout << "\n\n\n\n\ \t Choose the opeation: \n \t 0-Exit. \n\t 1-Create list. \n \t 2-Show list. \n \t 3-Sort by base. \n \t 4-Add element after k element. \n\t 5-Delete element after k element. \n\t 6-Save to file. \n\t 7-Load from file. \n \t >";
		cin >> operation;
		switch (operation)
		{
		case 0:
		{
			cout << "\n \t Exit.";
			return 0;
		}
		case 1:
		{
			int count;
			cout << "\n \t Enter a count of element of list: ";
			cin >> count;
			if (count < 1)
			{
				cout << "\n \t Count could not to be < 0.";
				continue;
			}
			else
			{
				Head = Create(Head, count);
			}
			break;
		}
		case 2:
		{
			ShowLinkedList(Head);
			break;
		}
		case 3:
		{
			Head = SortByBase(&Head);
			ShowLinkedList(Head);
			break;
		}
		case 4:
		{
			int k;
			cout << "\n \t Enter a k(start from 0): ";
			cin >> k;
			if (k < 0)
			{
				cout << "\n \t error";
				continue;
			}
			else
			{
				InsertAfterK(&Head, k);
				ShowLinkedList(Head);
			}
			break;
		}
		case 5:
		{
			int k;
			cout << "\n \t Enter a k(start from 0): ";
			cin >> k;
			if (k < 0)
			{
				cout << "\n \t error";
				continue;
			}
			else
			{
				DeleteAfterK(&Head, k);
				ShowLinkedList(Head);
			}
			break;
		}
		case 6:
		{
			SaveToFile(Head, fileName);
			ShowLinkedList(Head);
			break;
		}
		case 7:
		{
			LoadFromFile(&Head, fileName);
			ShowLinkedList(Head);
			break;
		}
		default:
		{
			cout << "\n \t Error. Undefined operation";
			return 0;
		}
		}
	}
	return 0;
}