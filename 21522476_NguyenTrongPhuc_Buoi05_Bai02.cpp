#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void create_auto(float a[])
{
	for (int i = 0; i < 1000; i++)
	{
		a[i] = rand() % 1000 + 10 + (float)0.1 * (rand() % 10);
	}
}
void xuat_mang(float a[])
{
	for (int i = 0; i < 1000; i++)
	{
		cout << a[i] << "\t";
	}
}
void selectionsort(float a[])
{
	int min;
	for (int i = 0; i < 1000 - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < 1000; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(a[min], a[i]);
	}
}
void insertionsort(float a[])
{
	int pos, x;
	for (int i = 1; i < 1000; i++)
	{
		x = a[i];
		pos = i - 1;
		while (pos >= 0 && x < a[pos])
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
double ThoiGianthucthi_SelectionSort(float a[])
{
	clock_t start_time, end_time;
	double period;
	start_time = clock();
	selectionsort(a);
	end_time = clock();
	period = ((double)(end_time - start_time)) / (CLOCKS_PER_SEC);
	return period;
}
double ThoiGianthucthi_InsertionSort(float a[])
{
	clock_t start_time, end_time;
	double period;
	start_time = clock();
	insertionsort(a);
	end_time = clock();
	period = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	return period;
}



int main()
{
	float a[1000];
	int choice=1;
	srand(time(NULL));
	while (choice > 0 && choice < 8)
	{
		cout << "-------------------MENU-----------------" << endl;
		cout << "1.Nhap thu cong cho mang arrayA" << endl;
		cout << "2.Khoi tao tu dong 100000 phan tu kieu so thuc cho mang arrayA" << endl;
		cout << "3.Xuat mang" << endl;
		cout << "4.Sap xep mang tang dan bang thuat toan chon truc tiep" << endl;
		cout << "5.Tinh thoi gian thuc hien sap xep mang tang dan bang thuat toan chon truc tiep" << endl;
		cout << "6.Sap xep mang tang dan bang thuat toan chen truc tiep" << endl;
		cout << "7.Tinh thoi gian thuc hien sap xep tang dan bang thuat toan chen truc tiep" << endl;
		cout << "0.THOAT" << endl;
		cout << "xin nhap lua chon!\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			break;
		case 2:
			create_auto(a);
			break;
		case 3:
			xuat_mang(a);
		case 4:
			selectionsort(a);
			cout << "\nmang da dc sap xep : ";
			xuat_mang(a);
			break;
		case 5:
			cout << "\nThoi gian thuc hien sap xep mang tang dan bang thuat toan chon truc tiep: " << ThoiGianthucthi_SelectionSort(a) << endl;
			break;
		case 6:
			insertionsort(a);
			cout << "\nmang da dc sap xep: ";
			xuat_mang(a);
			break;
		case 7:
			cout << "\nThoi gian thuc hien sap xep mang tang dan bang thuat toan chon truc tiep: " << ThoiGianthucthi_InsertionSort(a) << endl;
			break;
		case 0:
			cout << "\nket thuc";
			break;
		}
	}
	return 0;
}