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
void insertTail(list& l, int val)
{
	NODE* p = createNODE(val);
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}
NODE* deleteHead(list& l)
{
	NODE* p = l.head;
	if (p == NULL)
		return NULL;
	else
	{
		l.head = l.head->next;
		p->next = NULL;
		return p;
	}
}

bool isEmpty(list l)
{
	if (l.head == NULL)
		return true;
	return false;
}
typedef list queue;
void enqueue(queue& l, int val)
{
	insertTail(l, val);
}
int dequeue(queue& l)
{
	NODE* p = deleteHead(l);
	if (p == NULL)
		return -1;
	return p->value;
}
int rear(queue l)
{

	NODE* p = l.tail;
	if (l.head == NULL)
		return NULL;
	return p->value;
}
int front(queue l)
{

	NODE* p = l.head;
	if (p == NULL)
		return NULL;
	return p->value;
}
int main()
{
	int x = 1;
	while (x > 0 && x < 7)
	{
		cout << "\n----------------MENU------------------";
		cout << "\n1.khoi tao stack:";
		cout << "\n2.kiem tra stack rong: ";
		cout << "\n4.day mot phan tu vao stack: ";
		cout << "\n5.lay mot phan tu ra khoi stack: ";
		cout << "\n6.xuat ra top cua stack: ";
		cout << "\n nhap lua hon cua ban: ";
		cin >> x;

		switch (x)
		{
		case 1:
			queue l;
			initlist(l);
			break;
		case 2:
			cout << isEmpty(l);
			break;
		case 4:
			int e;
			cout << "\nnhap mot so ban can them vao queue: ";
			cin >> e;
			enqueue(l, e);
			break;
		case 5:
			cout << dequeue(l);
			break;
		case 6:
			cout << rear(l);
			cout << front(l);
			break;
		}
	}

	return 0;


}