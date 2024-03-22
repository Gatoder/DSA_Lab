//STT
//Họ và Tên: Nguyễn Trọng Phúc
//Buổi: 01-bài 02
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Nhap(int A[100], int sl)
{
	
	for (int i = 0; i < sl; i++)
	{
		cout << "nhap so: ";
		cin >> A[i];
	}
}
void Nhaptudong(int A[100], int& sl)
{
	srand(time(NULL));
	sl = rand() % 41 + 10;
	for (int i = 0; i < sl; i++)
	{
		A[i] = rand() % 1999 - 999;
	}
}
void xuat(int A[100], int sl)
{
	for (int i = 0; i<sl; i++)
		cout << A[i] << " ";
}
int main()
{
	int a = 1;
	int A[100];
	int n, c;
	while (a != 0)
	{
		cout << "\n========================menu====================";
		cout << "\n1. Nhap tay: ";
		cout << "\n2.Nhap tu dong: ";
		cout << "\n3.xuat";
		cout << "nhap lua chon: ";
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "nhap sl pt: "; cin >> n;
			Nhap(A, n);
			break;
		case 2:
			Nhaptudong(A, c);
			break;
		case 3:
			xuat(A, c);
			break;
		}
	}
	return 0;
}