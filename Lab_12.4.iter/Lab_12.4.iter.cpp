#include <iostream>
#include <iomanip>
using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value; 
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link; 
		T->link = tmp;
	}
	else
	{
		L = tmp;
	}
	tmp->link = L;
}

int Count(Elem* L)
{
	if (L == NULL)
		return 0;
	Elem* first = L;
	int k = 0;
	do
	{
		if (L->info < 0)
			k++;
		L = L->link;
	} while (L != first);

	return k;
}

void Print(Elem* L)
{
	if (L == NULL)
		return;
	Elem* first = L;
	cout << setw(4) << L->info;
	while (L->link != first)
	{
		L = L->link;
		cout << setw(4) << L->info;
	}
	cout << endl;
}

int main()
{
	Elem* L = NULL;
	for (int i = -2; i < 3; i++)
		Insert(L, i);
	
	cout << "given list: " << endl;
	Print(L);
	cout << endl;
	cout << "Count of number with negative values: ";
	cout << Count(L) << endl;
	
	return 0;
}