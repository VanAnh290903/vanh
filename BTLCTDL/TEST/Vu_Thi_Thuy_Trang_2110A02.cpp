#include<bits/stdc++.h>
using namespace std;
/*
Mon: Cau truc du lieu va giai thuat
Thuc hanh: Cai dat chuong trinh voi cay nhi phan tim kiem chua cac so nguyen
-tao
-duyet
-tim kiem
-xoa
-in phan tu tang dan

Tên:Vũ Thị Thùy Trang
Lớp: 2110A02
MSV: 21A100100391
*/
struct Node{
    int Infor;
    Node *Left;
    Node *Right;
};

typedef Node *Tree;

Node *CreateNode(int init)
{

    Node *p = new Node;
    p->Infor = init;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}

void CreateTree(Tree &root)
{
    root = NULL;
}

void DestroyTree(Tree &root)
{
    if(root)
    {
        DestroyTree(root->Left);
        DestroyTree(root->Right);
        delete root;
    }
}
void AddNode(Tree &root, Node *node)
{
    if(root)
    {

        if(root->Infor == node->Infor)
            return;
        if(node->Infor < root->Infor)
            AddNode(root->Left, node);
        else
            AddNode(root->Right, node);
    }
    else{
        root = node;
    }
}

Node *SearchTree(Tree Root, int x)
{
    Node *p = Root;
    while (p!=NULL)
    {
        if(x == p->Infor)
            return p;
        else if(x < p->Infor)
            p = p->Left;
        else
            p = p->Right;
    }
    return NULL;
}

Node *FindNode(Tree root, int x)
{

    if(root)
    {
        if(root->Infor ==x)
            return root;
        if(x<root->Infor)
            return FindNode(root->Left, x);
        return FindNode(root->Right, x);
    }
    return NULL;
}

void FindAndReplace1(Tree &p, Tree &tree)
{

    if(tree->Left)
        FindAndReplace1(p, tree->Left);
    else{
        p->Infor = tree->Infor;
        p = tree;
        tree = tree->Right;
    }
}

void FindAndReplace2(Tree &p, Tree &tree)
{

    if(tree->Right)
        FindAndReplace2(p, tree->Right);
    else{
        p->Infor = tree->Infor;
        p = tree;
        tree = tree->Left;
    }
}
void DeleteNode(Tree &root, int x)
{
    if(root)
    {
        if(x > root->Infor)
            DeleteNode(root->Right, x);
        else if(x < root->Infor)
            DeleteNode(root->Left, x);
        else{
            Node *p = root;
            if(!root->Left)
                root = root->Right;
            else if(!root->Right)
                root = root->Left;
            else
                FindAndReplace1(p, root->Right);
//                FindAndReplace2(p, root->Left);
            delete p;
        }

    }
    else{
        cout<< "\n Khong tim thay phan tu can xoa!\n";
    }

}

void PrintTree_LNR(Tree root)
{
    if(root)
    {
        PrintTree_LNR(root->Left);
        cout<<root->Infor<<' ';
        PrintTree_LNR(root->Right);
    }
}
int main()
{
    Tree T;
    int n;
    int a[n];
    int i,x;
    n = sizeof a/sizeof(int);

    Node *p;

    int chon;
    do{
        cout<<"\n1. Nhap mang a";
        cout<<"\n2. Tao cay";
        cout<<"\n3. Chen lan luot cac phan tu vao cay";
        cout<<"\n4. Duyet cay LNR";
        cout<<"\n5. Tim kiem de quy";
        cout<<"\n6. Tim kiem khong de quy";
        cout<<"\n7. Xoa phan tu x";
        cout<<"\n0. Thoat chuong trinh\n";
        cout<<"Moi chon: ";
        cin>>chon;

        switch(chon)
        {
        case 1:
            cout<<"Nhap n:";
            cin>>n;
            cout<<"\nNhap phan tu mang a\n";
            for(i=0; i<n; i++)
            {
                cin>>a[i];
            }
            break;
        case 2:
            CreateTree(T);
            break;
        case 3:
            //Chen lan luot cac phan tu vao cay
            for(i=0; i<n; i++)
            {

                Node *p = new Node();
                p = CreateNode(a[i]);
                AddNode(T, p);

            }
            break;
        case 4:
            //Duyet cay tang dan LNR
            cout<<"\nDuyet LNR:";
            PrintTree_LNR(T);
            cout<<endl;
            break;
        case 5:
            //Tim kiem de quy
            cout<<"\n Nhap x can tim: "; cin>>x ;
            p = FindNode(T,x);
            if(p!=NULL)
                cout<<"\n Tim thay - de quy"<<endl;
            else
                cout<<"\n Khong tim thay" <<endl;
            break;
        case 6:
            //Tim kiem - khong de quy
            int y;
            cout<<"\n Nhap y can tim: "; cin>>y ;
            p = SearchTree(T, y);
            if(p!=NULL)
                cout<<"\n Tim thay - khong de quy" <<endl;
            else
                cout<<"\n Khong tim thay - khong de quy"<<endl;
            break;
        case 7:
            //Xoa phan tu
            cout<<"\n Nhap x can xoa: "; cin>>x;
            DeleteNode(T,x);
            cout<<"\n Sau khi xoa x:";
            PrintTree_LNR(T);
            cout<<endl;
            break;
        case 0:
            exit(0);
        default:
            cout<<"Ban nhap sai roi moi nhap lai";
        }
    } while(chon!=0);
    return 0;




}
