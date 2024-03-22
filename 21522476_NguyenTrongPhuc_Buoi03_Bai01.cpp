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
void initlist(list &l)
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
void insertHead(list &l, int val)
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
	if (p == NULL)
		return NULL;
	else
	{
		l.head = l.head->next;
		p->next = NULL;
		return p;
	}
}


typedef list stack;



void push(stack& l, int val)
{
	insertHead(l, val);
}

int pop(stack& l)
{
	NODE* p = deleteHead(l);
	
	if (p == NULL)
		return -1;
	return p->value;
}
int top(stack& l)
{
	NODE* p = l.head;
	if (p == NULL)
		return NULL;
	return p->value;
}
bool isEmpty(stack l)
{
	if (l.head == NULL)
		return true;
	else
		return false;

}
int main()
{
	int x= 1;
	//stack a;
	//initlist(a);
	//push(a, 3);
	//push(a, 5);
	//cout<< pop(a);
	//cout << isEmpty(a);
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
			stack l;
			initlist(l);
			break;
		case 2:
			cout<<isEmpty(l);
			break;
		case 4:
			int e;
			cout << "\nnhap mot so ban can push: ";
			cin >> e;
			push(l, e);
			break;
		case 5:
			cout<<pop(l);
			break;
		case 6:
			cout << top(l);
			break;
		}
	} 
	
	return 0;


}