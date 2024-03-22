
//Họ và tên : Nguyễn Trọng Phúc
//Buổi 2- bài 2
//
#include <iostream>
using namespace std;

struct donthuc
{
	int coSo;
	int soMu;
};
donthuc nhap_ps()
{
	donthuc a;
	cout << "nhap co so: ";
	cin >> a.coSo;
	cout << "nhap so mu: ";
	cin >> a.soMu;
	return a;
}
void xuat_ps(donthuc a)
{
	if (a.coSo >= 0)
		cout << "+" << a.coSo << "x^" << a.soMu;
	else
		cout << a.coSo << "x^" << a.soMu;
}
struct NODE
{
	donthuc value;
	NODE* next;
};
struct list
{
	NODE* head;
	NODE* tail;
};
void initlist(list& l)
{
	l.head = l.tail = NULL;
}
NODE* createNODE(donthuc value)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->value = value;
	p->next = NULL;

	return p;
}
void insertTail(list& l, donthuc val)
{
	NODE* p = createNODE(val);
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	l.tail->next = p;
	l.tail = p;
}
void nhap(list& l)
{
	int n;
	cout << "nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		donthuc val = nhap_ps();
		insertTail(l, val);
	}
}
void xuat(list l)
{
	NODE* head = l.head;
	cout<<(head->value).coSo<<"x^"<<(head->value).soMu;
	head = head->next;
	while (head != NULL)
	{
		xuat_ps(head->value);
		head = head->next;
	}
}

int main()
{
	list l;
	initlist(l);
	nhap(l);
	xuat(l);
	return 0;
}