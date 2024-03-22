#include <iostream>
#include<time.h>

using namespace std;

void auto_x(int array[], int& n)
{

	n = rand() % 21 + 30;
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 900 + 100;
	}
}
void auto_y(int array[], int& n)
{
	int x;
	n = rand() % 21 + 30;
	array[0] = rand() % 31 + 100;
	for (int i = 1; i < n; i++)
	{
		array[i] = array[i - 1] + rand() % 16;
	}
}
void xuat_mang(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << "\t";
	}
}
int linearsearch(int array[], int n, int x, int& count)
{
	for (int i = 0; i < n; i++)
	{
		count++;
		if (array[i] == x)
			return i;
	}
	return 0;
}
int binarysearch(int array[], int l, int r, int x, int& count)
{
	if (r >= 1)
	{
		count++;
		int mid = (l + r) / 2;
		if (array[mid] == x)
			return mid;
		if (array[mid] < x)
		{
			return binarysearch(array, mid + 1, r, x, count);
		}
		return binarysearch(array, l, mid - 1, x, count);
	}
	return 0;
}
int compare_linear_and_binary(int array[], int n, int x)
{
	int c1, c2;
	linearsearch(array, n, x, c1);
	binarysearch(array, 0, n - 1, x, c2);
	if (c1 > c2)
		return 1;
	if (c1 < c2)
		return-1;
	return 0;
}

void Menu()
{
    srand(time(NULL));
    int Choice;
    char SubChoice;
    int nX, nY;
    int count1, count2;
    int value;
    int x[100], y[100];
    int Loop = 1;
    while (Loop)
    {
        cout << "\n----------MENU----------\n";
        cout << "1. Tao mang\n";
        cout << "\t A. Tao mang arrayX\n";
        cout << "\t B. Tao mang arrayY\n";
        cout << "2. Xuat mang\n";
        cout << "\t A. Xuat mang arrayX\n";
        cout << "\t B. Xuat mang arrayY\n";
        cout << "3. Tim kiem tuyen tinh\n";
        cout << "\t A. Ap dung mang arrayX\n";
        cout << "\t B. Ap dung mang arrayY\n";
        cout << "4. Tim kiem nhi phan, ap dung mang arrayY\n";
        cout << "5. So sanh so lan tim kiem, ap dung mang arrayY\n";
        cout << "---------- END ----------\n";
        cout << "\t Xin moi lua chon: ...!!!\n";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            cout << "\t A. Tao mang arrayX\n";
            cout << "\t B. Tao mang arrayY\n";
            cin >> SubChoice;
            switch (SubChoice)
            {
            case 'A':
                auto_x(x,nX);
                cout << "\t Da tao gia tri arrayX!\n";
                break;
            case 'B':
                auto_y(y,nY);
                cout << "\t Da tao gia tri arrayY!\n";
                break;
            default:
                break;
            }
            break;
        case 2:
            cout << "\t A. Xuat mang arrayX\n";
            cout << "\t B. Xuat mang arrayY\n";
            cin >> SubChoice;
            switch (SubChoice)
            {
            case 'A':
                xuat_mang(x,nX);
                break;
            case 'B':
                xuat_mang(y,nY);
                break;
            default:
                break;
            }
            break;
        case 3:
            cout << "Nhap gia tri can tim: ";
            cin >> value;
            cout << "\t A. Ap dung mang arrayX\n";
            cout << "\t B. Ap dung mang arrayY\n";
            cin >> SubChoice;
            switch (SubChoice)
            {
            case 'A':
                count1 = 0;
                cout << "\t" << linearsearch(x,nX,value,count1) << endl;
                break;
            case 'B':
                count2 = 0;
                linearsearch(y,nY,value,count2);
                cout << count2 << endl;
                break;
            default:
                break;
            }
            break;
        case 4:
            cout << "Nhap gia tri can tim: ";
            cin >> value;
            count1 = 0;
            binarysearch(y,0,nY-1,value,count1);
            cout << count1 << endl;
            break;
        case 5:
            cout << "Nhap gia tri can tim: ";
            cin >> value;
            cout << "\t" << compare_linear_and_binary(y,nY,value) << endl;
            break;
        default:
            Loop = 0;
            break;
        }
    }
}

int main()
{
    Menu();
    return 0;
}