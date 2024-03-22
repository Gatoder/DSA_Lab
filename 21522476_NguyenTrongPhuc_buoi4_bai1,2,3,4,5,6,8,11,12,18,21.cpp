#include <iostream>
#include<time.h>
using namespace std;

struct Node
{
    int value;
    Node* right;
    Node* left;
};

struct Tree
{
    Node* root;
};

Node* createNode(int val)
{
    Node* p = new Node();
    if (p->right == NULL && p->left == NULL)
    {
        return NULL;
    }
    p->value = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void initTree(Tree& T)
{
    T.root = NULL;
}

void insertTree(Node* &root, int val)
{
    Node* p = createNode(val);
    if (root != NULL)
    {
        if (root->value == val)
        {
            return;
        }
        else if (root->value > val)
        {
            insertTree(root->left, val);
        }
        else
        {
            
            insertTree(root->right, val);
        }
    }
    root = p; // sau khi thêm vào cuối cây trả về gốc ban đầu để duyệt lại từ đầu 

}
void nhapauto(Node* root)
{
    srand(time(NULL));
    int a = rand() % 10 + 11;
    for (int i = 0; i < 10; i++)
    {
        insertTree(root,rand() % 358 + 301);
    }
}
void DuyetcayLNR(Node* root)
{
    if (root != NULL)
    {
        DuyetcayLNR(root->left);
            cout << root->value << "-";
        DuyetcayLNR(root->right);
    }
}
void DuyetcayNLR(Node *root)
{
    if (root != NULL)
    {
        DuyetcayNLR(root->right);
        cout << root->value << "-";
        DuyetcayNLR(root->left);
    }

}
void DuyetcayLRN(Node* root)
{
    if (root != NULL)
    {
        DuyetcayLRN(root->left);
        DuyetcayLRN(root->right);
        cout << root->value << "-";
    }
}
bool timkiem(Node* root, int X)
{
    Tree p;
    if (root->value == X)
        return true;
    if (root == NULL)
        return NULL;
    if (timkiem(root->left, X) == NULL)
        timkiem(root->right, X);

    else
        return false;
}
int CountNode(Node *root) {
    if (root == NULL)
        return 0;
    else
        return 1 + CountNode(root->left) + CountNode(root->right);
}
int CountsmallerNode(Node* root, int x) {
    if (root == NULL)
        return 0;
    else
    {
        if (root->value > x)
            return CountsmallerNode(root->left, x);
        else
            return 1 + CountsmallerNode(root->left, x) + CountsmallerNode(root->right, x);
    }
}
int CountbiggerNode(Node* root, int x) {
    if (root == NULL)
        return 0;
    else
    {
        if (root->value > x)
            return 1 + CountbiggerNode(root->left, x) + CountbiggerNode(root->right, x);
        else
            return CountbiggerNode(root->right, x);
    }
}
int sumoddnumberNode(Node* root)
{
    if (root == NULL)
        return 0;
    else
    {
        if (root->value % 2 != 0)
            return root->value + sumoddnumberNode(root->left) + sumoddnumberNode(root->right);
        else
            return sumoddnumberNode(root->right) + sumoddnumberNode(root->left);
    }
}


int main()
{
    Tree T;
    initTree(T);
    int x, a = 1;

    while (a < 1 || a > 10)
    {
        cout << "========menu========\n";
        cout << "1.viet ham chua gia tri du lieu\n";
        cout << "2.viet ham nhap gia tri cho cay theo cach thu cong\n";
        cout << "3.ham nhap tu dong\n";
        cout << "4.duyet theo NLR, LNR,LRN\n";
        cout << "5.tim gia tri x nhap tu ban phim\n";
        cout << "6.xoa mot gia tri\n";
        cout << "7.dem toan bo node cua cay\n";
        cout << "8. dem node co gia tri nho hon\n";
        cout << "9.viet ham co gia tri lon hon\n";
        cout << "10.viet ham tong cac node le\n";

        switch (a)
        {
        case 1:
            break;
        case 2:
            cout << " nhap gia tri can chen: ";
            cin >> x;
            break;
        case 3:
            nhapauto(T.root);
            break;
        case 4:
            DuyetcayLNR(T.root);
            DuyetcayLRN(T.root);
            DuyetcayNLR(T.root);
            break;
        case 5:
            cout << "nhap gia tri can tim : ";
            cin >> x;
            timkiem(T.root, x);
            break;
        case 6:
            break;
        case 7:
            cout << CountNode(T.root);
            break;
        case 8:
            cout << CountsmallerNode(T.root,x);
            break;
        case 9:
            cout << CountbiggerNode(T.root, x);
            break;
        case 10:
            cout << sumoddnumberNode(T.root);
            break;
        }
    }
    return 0;

}
