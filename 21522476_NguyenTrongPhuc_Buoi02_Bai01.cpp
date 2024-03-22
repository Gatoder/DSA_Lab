
//Họ và tên: Nguyễn Trọng Phúc
//Buổi 2- bài 1(cơ bản)
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
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
	l.head = l.tail = NULL;
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
	p->next = l.head;
	l.head = p;
}
void insertTail(list &l, int val)
{
	NODE* p = createNODE(val);
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	l.tail->next= p;
	l.tail = p;
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
void nhap_random(list &l)
{
	srand(time(NULL));
	int val;
	for (int i = 0; i < rand() % 21 + 39; i++)
	{
		val = rand() % 198 - 99;
		insertTail(l, val);
	}
}
void nhap_frommang1chieu(list &l, int A[], int sl)
{
	for (int i = 0; i < sl; i++)
	{
		insertHead(l, A[i]);
	}
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
void xuat_kem_diachi(list l)
{
	NODE* head = l.head;
	while (head != NULL)
	{
		cout <<" \ndiachi: "<<&head <<" " << head->value << "->";
		head = head->next;
	}
}
int tim_max(list l)
{
	NODE* head = l.head;
	int max = head->value;
	while (head != NULL)
	{
		if (head->value > max)
		{
			max = head->value;
			head = head->next;
		}
	}
	return max;
}
int tim_min(list l)
{
	NODE* head = l.head;
	int min = head->value;
	while (head != NULL)
	{
		if (head->value < min)
		{
			min = head->value;
			head = head->next;
		}
	}
	return min;
}
int main()
{
	int* A;
	list l;
	int n,a;
	do {
		cout << "\n------------menu-------------";
		cout << "\n1.Xay dung cau truc node và cau truc danh sach lien ket don.";
		cout << "\n2.Ham khoi tao danh sach lien ket don va khoi tao dia chi node tu mot so nguyen.";
		cout << "\n3Chen node vao dau danh sach.";
		cout << "\n4.Chen node cao cuoi danh sach.";
		cout << "\n5.Nhap thu cong cho danh sach.";
		cout << "\n6.Nhap gia tri cho danh sach theo yeu cau random.";
		cout << "\n7.Nhap gia tri cho danh sach tu mang mot chieu.";
		cout << "\n8.In ra danh sach da nhap.";
		cout << "\n9.In ra danh sach kem dia chia.";
		cout << "\nNhap lua chon: ";
		cin >> a;
		switch (a)
		{
		case 1:
			break;
		case 2:
			initlist(l);
			createNODE(5);
			break;
		case 3:
			insertHead(l, 5);
			break;
		case 4:
			insertTail(l, 4);
			break;
		case 5:
			nhap_thucong(l);
			cout << "\nket qua phep nhap:" << endl;
			xuat(l);
			break;
		case 6:
			nhap_random(l);
			cout << "\nket qua phep nhap:" << endl;
			xuat(l);
			break;
		case 7:
			cout << "nhap so luong phan tu mang: ";
			cin >> n;
			A = new int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "nhap phan tu thu" << i + 1;
				cin >> A[i];
			}
			nhap_frommang1chieu(l,A,n);
			cout << "\nket qua phep nhap:" << endl;
			xuat(l);
			break;
		case 8:
			cout << "xuat theo lua chon ng dung: "<<endl;
			xuat(l);
			break;
		case 9:
			cout << "xuat kem dia chi: ";
			xuat_kem_diachi(l);
			break;
		}
	} while (a != 0);
	return 0;
}