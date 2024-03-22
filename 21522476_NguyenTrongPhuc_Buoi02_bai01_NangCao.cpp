//Họ và tên: Nguyễn Trọng Phúc
//Buổi 02-bài 1.nâng cao

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
NODE* createNODE(int value)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->value = value;
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
	else {
		p->next = l.head;
		l.head = p;
	}
}
void nhap_thucong(list &l)
{
	int val;
	do {
		cout << "nhap gia tri can nhap: ";
		cin >> val;
		insertHead(l, val);
	} while (val != 0);
	
}
void xuat(list l)
{
	NODE* head = l.head;
	while (head != NULL)
	{
		cout << head->value << "->";
		head = head->next;
	}
}

//phần trên là em bonus thêm để chương trình không báo lỗi ạ
//Phần dưới là phần yêu cầu(nâng cao):


void dao_nguoc(list &l)
{
	NODE* crr = l.head;
	NODE* prev = NULL;
	NODE* next = NULL;
	//l.tail = l.head;
	while (crr != NULL)
	{
		next = crr->next;
		crr->next = prev;

		prev = crr;
		crr = next;
	}
	l.head = prev;
}
void sapxep_tangdan(list &l)
{
	NODE* p = l.head;
	while (p != NULL)
	{
		NODE* t = p->next;
		while (t != NULL)
		{
			if (t->value < p->value)
			{
				int a = t->value;
				t->value = p->value;
				p->value = a;
			}
			t = t->next;
		}
		p = p->next;
	}
}
void sapxep_giamdan(list& l)
{
	NODE* p = l.head;
	while (p != NULL)
	{
		NODE* t = p->next;
		while (t != NULL)
		{
			if (t->value > p->value)
			{
				int a = t->value;
				t->value = p->value;
				p->value = a;
			}
			t = t->next;
		}
		p = p->next;
	}
}


int main()
{
	list l;
	initlist(l);
	nhap_thucong(l);
	xuat(l);

	dao_nguoc(l);
	cout << "\ndao nguoc: "<<endl;
	xuat(l);
	
	sapxep_tangdan(l);
	cout << "\nsap xep tang dan: " << endl;
	xuat(l);

	sapxep_giamdan(l);
	cout << "\nsap xep giam dan: " << endl;
	xuat(l);
	return 0;
}