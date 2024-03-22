// STT
//Họ và Tên: Nguyễn Trọng Phúc
//buổi: 01-bài 02

#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct DonThuc
{
	int soMu, heSo;
};
void Nhap1donthuc(DonThuc &a)
{
	cout << "nhap he so: "; cin >> a.heSo;
	cout << "nhap so mu: "; cin >> a.soMu;
}
void nhapdttudong(DonThuc &x)
{
	x.heSo = rand() % 41 + 39;
	x.soMu = rand() % 10;
}
void Xuat(DonThuc a)
{
	cout << a.heSo << "x^" << a.soMu;
}
/*void nhapdathuc(DonThuc A[100], int& n)
{
	cout << "nhap so luon don thuc can co: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		Nhap1donthuc(A[i]);
}*/

void NhapDTtudong(DonThuc B[100],int&sl)
{
	srand(time(NULL));
	sl = rand()%10 + 1;
	for (int i = 0; i < sl; i++)
		nhapdttudong(B[i]);
}
void xuatdathuc(DonThuc B[100], int sl)
{
	cout << "y=f(x)=";
	for (int i = 0; i < sl; i++)
	{
		if (i == 0)
		{
			Xuat(B[i]);
		}
		else if(i>0)
		{
			if (B[i].heSo >= 0)
			cout << "+";
			Xuat(B[i]);
		}
	}
}
float tinh_y(DonThuc B[100], int sl, int x)
{
	float a=0;
	for (int i = 0; i < sl; i++)
	{
		a = a + pow(B[i].heSo * x, B[i].soMu);
	}
	return a;
}
DonThuc tim_kiemmax(DonThuc B[100], int sl)
{
	int c = 0;
	DonThuc a;
	for (int i = 0; i < sl; i++)
	{
		if (B[i].soMu > c)
		{
			c = B[i].soMu;
			a = B[i];
		}
	}
	return a;
}
DonThuc tim_kiemmin(DonThuc B[100], int sl)
{
	int c = B[0].soMu;
	DonThuc a;
	for (int i = 0; i < sl; i++)
	{
		if (B[i].soMu < c)
		{
			c = B[i].soMu;
			a = B[i];
		}
	}
	return a;
}

int main()
{
	DonThuc z;
	DonThuc y, A[100], B[100];
	int sl;
	float x;
	int a = 1;
	while (a >= 1 && a <= 6)
	{
		cout << "\n====================MENU===========================";
		cout << "\n1.Nhap thu cong cho tung don thuc";
		cout << "\n2.Ham nhap cho tung don thuc theo cach tu dong.";
		cout << "\n3.xuat don thuc.";
		cout << "\n4.tinh gia tri y=f(x).";
		cout << "\n5. tim kiem da thuc co bac lon nhat.";
		cout << "\n6.tim don thuc co bac nho nhat.";
		cout << "\n nhap lua chon cua ban: ";
		cin >> a;
		switch (a)
		{
		case 1:
			Nhap1donthuc(z);
			break;
		case 2:
			NhapDTtudong(B, sl);
			break;

		case 3:
			xuatdathuc(B, sl);
			break;
		case 4:
			cout << "nhap x:= ";
			cin >> x;
			cout << "tinh y la : " << tinh_y(B, sl, x);
		case 5:
			Xuat(tim_kiemmax(B, sl));
			break;
		case 6:
			Xuat(tim_kiemmin(B, sl));

		}
	}
	return 0;
}