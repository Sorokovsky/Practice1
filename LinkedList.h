#pragma once
#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>
using namespace std;
struct LinkedList
{
	char numbers[16];
	int base;
	LinkedList* Next;
};
int CanStop(char ch)
{
	return ch == '\r' || ch == '\n';
}
LinkedList* EnterNumbersSystem()
{
	LinkedList* t1 = new LinkedList();
	cout << "\n \t Enter base: ";
	cin >> t1->base;
	char ch;
	int j = 0;
	cout << "\n \t Enter a numbers: \n \t > ";
	do
	{
		ch = _getch();
		cout << ch;
		int number = ch - '0';
		if (CanStop(ch)) break;
		if ((number >= t1->base) || !isdigit(ch))
		{
			cout << "\n \t Invalid number: number can not be nore than base. \n \t >";
			continue;
		}
		else
		{
			j++;
			t1->numbers[j - 1] = ch;
		}
	} while (j < 16);
	t1->numbers[j] = '\0';
	return t1;
}

LinkedList* Create(LinkedList* Head, int n)
{
	LinkedList* t1, * t2;
	for (int i = 0; i < n; i++)
	{

		t1 = EnterNumbersSystem();

		if (!Head)
		{
			Head = t1;
		}
		else
		{
			t2 = Head;
			while (t2->Next != NULL)
			{
				t2 = t2->Next;
			}
			t2->Next = t1;
		}
	}
	return Head;
}

void ShowLinkedList(LinkedList* Head)
{
	if (Head == NULL)
	{
		cout << "\n \t Error LinkedList is NULL";
		return;
	}
	LinkedList* Current = Head;
	cout << "\n \t Linked List: ";

	do
	{
		cout << "\n \t Base: " << Current->base << ", Numbers: " << Current->numbers;
		Current = Current->Next;
	} while (Current != NULL);
}

void Swap(LinkedList** Head, LinkedList** prev, LinkedList** first, LinkedList** second)
{
	LinkedList* Current = *first;
	LinkedList* Next = *second;
	Current->Next = (*second)->Next;
	Next->Next = Current;
	if (*prev == NULL)
	{
		*Head = Next;
	}
	else
	{
		(*prev)->Next = Next;
	}
}

LinkedList* SortByBase(LinkedList** Head)
{
	LinkedList* Current = *Head;
	int mustSort = 0;
	do
	{
		LinkedList* Checker = *Head;
		while (Checker != NULL && Checker->Next != NULL)
		{
			if (Checker->base > Checker->Next->base)
			{
				mustSort = 1;
				break;
			}
			Checker = Checker->Next;
		}
		if (mustSort)
		{
			LinkedList* Prev = NULL;
			Current = *Head;
			while (Current != NULL && Current->Next != NULL)
			{
				if (Current->Next != NULL && Current->base > Current->Next->base)
				{
					Swap(Head, &Prev, &Current, &Current->Next);
				}
				Prev = Current;
				Current = Current->Next;
			}
			mustSort = 0;
		}
		else
		{
			break;
		}
	} while (true);
	return *Head;
}

void InsertAfterK(LinkedList** Head, int k)
{
	int length = 0;
	if (length < k)
	{
		cout << "\n \t Error element of k undefined";
		return;
	}

	LinkedList* New = EnterNumbersSystem();
	LinkedList* Current = *Head;
	LinkedList* Cur = *Head;
	int i = 0;
	while (Current != NULL)
	{
		if (i == k)
		{
			LinkedList* Next = Current->Next;
			New->Next = Next;
			Current->Next = New;
			break;
		}
		i++;
		Current = Current->Next;
	}
}
void DeleteAfterK(LinkedList** Head, int k)
{
	LinkedList* Current = *Head;
	int i = 0;
	while (Current != NULL)
	{
		if (i == k)
		{
			LinkedList* Next = Current->Next;
			if (Next != NULL)
			{
				Current->Next = Next->Next;
				delete(Next);
				return;
			}
		}
		i++;
		Current = Current->Next;
	}
	cout << "\n \t Error. K element undefined";
}

void SaveToFile(LinkedList* Head, char fileName[])
{
	ofstream file;
	file.open(fileName, ios::trunc | ios::binary);
	if (!file.is_open())
	{
		cout << "\n \t Error. file not opened";
	}
	else
	{
		LinkedList* Current = Head;
		while (Current != NULL)
		{
			file.write((char*)Current, sizeof(*Current));
			Current = Current->Next;
		}
	}
	file.close();
}
LinkedList* LoadFromFile(LinkedList** Head, char fileName[])
{
	ifstream file;
	file.open(fileName, ios::binary | ios::out);
	if (!file.is_open())
	{
		cout << "\n \t Error. File not opened";
	}
	else
	{
		*Head = new LinkedList();
		LinkedList* Current = *Head;
		LinkedList* Prev = NULL;
		while (file.read((char*)Current, sizeof(*Current)))
		{
			if (Prev == NULL)
			{
				*Head = Current;
			}
			else
			{
				Prev->Next = Current;
			}
			Prev = Current;
			Current = new LinkedList();
		}
		Current->Next = NULL;
	}
	file.close();
	return *Head;
}