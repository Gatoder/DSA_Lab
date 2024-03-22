
#include <iostream>
#include <string>

using namespace std;

struct channel
{
	string ten;
	long subscirbe;
	int so_luong_vd;
};
struct NODE
{
	channel value;
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
NODE* createNODE()
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	cout << "nhap ten kenh : ";
	cin.ignore();
	getline(cin, p->value.ten);
	cout << "nhap so luong subscribe: ";
	cin >> p->value.subscirbe;
	cout << "nhap so luong vd: ";
	cin >> p->value.so_luong_vd;
	p->next = NULL;
	return p;
}
void subscribe(list& l)
{
	NODE* p = createNODE();
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
void xuat(list& l)
{
	NODE* p;
	p = l.head;
	while (p != NULL)
	{
		cout << p->value.ten << "subscribe:" << p->value.subscirbe << p->value.so_luong_vd << "vd";
		p = p->next;
	}
}
int return_sl_kenh(list l)
{
	int count = 0;
	NODE* p = l.head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}
void subscribe_nhieu_nhat(list l)
{
	NODE* p = l.head;
	long max = l.head->value.subscirbe;
	while (p != NULL)
	{
		if (p->value.subscirbe > max)
			max = p->value.subscirbe;
		p = p->next;
	}
	p = l.head;
	while (p != NULL)
	{
		if (p->value.subscirbe == max)
			cout << p->value.ten;
	}
}
int unsubscribe(list& l)
{
	NODE* p = l.head;
	if (p == NULL)
		return NULL;
	else
	{
		l.head = l.head->next;
		p->next = NULL;
		cout << p->value.ten;
		return 1;
	}
}
int main()
{
	int x = 1;
	while (x > 0 && x < 7)
	{
		cout << "\n==============MENU++++++++++++";
		cout << "\n1.subscribe kenh moi.";
		cout << "\n2.hien thi thongtin cac kenh trong danh sach.";
		cout << "\n3.hien thi thong tin kenh co luot dang ki nhieu nhat.";
		cout << "\n4.hien thi tong so kenh da dang ki.";
		cout << "\n5.unsubscribe  mot kenh.";
		cout << "\nxin moi nhap lua chon!.";
		cin >> x;
		switch (x)
		{
		case 1:
			list l;
			initlist(l);
			cout << "nhap sl kenh muon nhap: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				subscribe(l);
			}
			break;
		case 2:
			xuat(l);
			break;
		case 3:
			cout << "sl kenh da dang ki la: " << return_sl_kenh(l);
			break;
		case 4:
			subscribe_nhieu_nhat(l);
			break;
		case 5:
			unsubscribe(l);
			break;
		}
	}
	return 0;
}