
#include <iostream>

using namespace std;
struct NODE
{
	int value;
	NODE* next;
};
struct list
{
	NODE* head;
	NODE* tail;
};
void initlist(list& l)
{
	l.head = NULL;
	l.tail = NULL;
}
NODE* createNODE(int val)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->value = val;
	p->next = NULL;
	return p;
}
void insertHead(list& l, int val)
{
	NODE* p = createNODE(val);
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
NODE* deleteHead(list& l)
{
	NODE* p = l.head;
	if (l.head == NULL)
		return NULL;
	else
	{
		NODE* b = l.head;
		l.head = b->next;
		NODE* q = new NODE(*b);
		delete b;
		return q;
	}
}
bool isEmpty(list l)
{
	if (l.head == NULL)
		return true;
	return false;
}

typedef list stack;


void push(list& l, int val)
{
	insertHead(l, val);
}

int pop(list& l)
{
	NODE* p = deleteHead(l);
	if (p == NULL)
		return -1;
	return p->value;
}

bool checkFraction(char bieuthuc[100])
{
	stack s;
	initlist(s);
	//cout << "nhap vao mot chuoi: ";
	//cin >> bieuthuc;
	for (int j = 0; j < strlen(bieuthuc); j++)
	{
		if (bieuthuc[j] == '(')
		{
			push(s, bieuthuc[j]);
		}
		if (bieuthuc[j] == ')')
		{
			if (isEmpty(s))
			{
				return false;
			}
			else
				pop(s);
		}
	}
	if (!isEmpty(s))
		return false;

	return true;
}

int main()
{
	bool check;
	char bieuthuc[100];
	cout << "nhap vao chuoi: ";
	cin >> bieuthuc;
	check = checkFraction(bieuthuc);
	if (checkFraction(bieuthuc))
		cout << "dung";
	else
		cout << "sai";
	return 0;
}