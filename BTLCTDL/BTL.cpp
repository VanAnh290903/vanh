/* Nhóm 3 - Quản lý danh sách khen thưởng học sinh */
#include<bits/stdc++.h>
using namespace std;
struct SinhVien
{
    int Masv, Sotc;
    char tenSV[50];
    char ngaySinh[15];
    char Khoa[20];
    char lopHC[20];
    char Gmail[30];
    char Gioitinh[5];
    float Diemht, Diemrl;

};
typedef struct SinhVien SV;

struct NodeSV
{
    SV info;
    struct NodeSV *next;
};

struct ListSV
{
    NodeSV *Head;
    NodeSV *Tail;
};
ListSV QLSV;
//===================

void initSV( ListSV &Q)
{
    Q.Head= NULL;
    Q.Tail = NULL;
};
NodeSV *getNodeQLSV( SinhVien x)
{
    NodeSV *p;
    p = new NodeSV();
    if(p==NULL)
    {
        cout<< "\n Khong Thanh Cong";
        exit(0);
    }
    p ->info=x;
    p->next = NULL;
    return p;
}
void NhapSV(SinhVien &x)
{
    cout << "\nNhap ma SV: ";
    cin>> x.Masv;
    cout<< "Nhap Ho Ten: ";
    fflush(stdin);
    cin.getline(x.tenSV,50);
    cout<< "Nhap ngay sinh: ";
    fflush(stdin);
    cin>>x.ngaySinh;
    cout<< "Khoa: ";
      fflush(stdin);
    cin.getline(x.Khoa,20);
    cout<< "Lop: ";

    cin.getline(x.lopHC,20);
    cout<< "Gmail: ";
    cin>> x.Gmail;
    cout<< "Gioi Tinh: ";
    cin>> x.Gioitinh;
    cout<< "Nhap diem hoc tap: ";
    cin>> x.Diemht;
    cout<< "Nhap diem ren luyen: ";
    cin>> x.Diemrl;
    cout<< "Nhap so tin chi: ";
    cin>> x.Sotc;
}
void hienSV(SinhVien x)
{
    cout << setw(20)<< "\n SV: "<< x.Masv
         << setw(20)<< x.tenSV
         << setw(15)<< x.ngaySinh
         << setw(10)<< x.Khoa
         << setw(10)<< x.lopHC
         << setw(15)<<x.Gmail
         << setw(4)<<x.Gioitinh
         << setw(3)<<x.Diemht
         << setw(3)<<x.Diemrl
         << setw(4)<<x.Sotc;
}
void chendauSV( ListSV &Q, NodeSV *p)
{
    if (Q.Head== NULL)
    {
        Q.Head =p;
        Q.Tail=p;
    }
    else
    {
        p->next=Q.Head;
        Q.Head =p;
    }
}
void nhapDSSV(ListSV &Q)
{
    int n, i;
    NodeSV *p;
    SinhVien x;
    cout<< "Nhap so sinh vien: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<< "\n--------------------------------\n";
        cout<< "Nhap sinh vien thu "<< i+1<<'\n';
        NhapSV(x);
        p= getNodeQLSV(x);
        chendauSV(Q,p);
        cout<< '\n';
    }
}
void indsSv(ListSV Q)
{
    NodeSV *p;
    cout<< "\n DANH SACH SINH VIEN ";
    for(p=Q.Head; p!=NULL; p=p->next)
    {
        hienSV(p->info);
    }
}
//Xóa phần tử đầu danh sách
void Xoaptudau( ListSV &Q)
{
    NodeSV *p;
    if(Q.Head != NULL )
    {
        p=Q.Head;
        Q.Head = Q.Head -> next;
        delete p;
        if(Q.Head==NULL )// xóa hết mảng
            Q.Tail=NULL;
    }
    indsSv(Q);
}
//Tìm kiếm một phần tử theo mã
void TimkiemMasv(ListSV DSPN)
{
    int x;
    int dem=0;
    cout << "\nNhap ma phieu can tim: ";
    cin>>x;
    NodeSV *p;
    for(p=DSPN.Head; p!=NULL; p=p->next)
    {
        if(p->info.Masv==x)
        {
            dem++;
            hienSV(p->info);
            break;
        }
    }
    if(dem==0)
    {
        cout<< "Khong co Sinh Vien nay!";
    }
}
//Sắp xếp danh sách theo điểm học tập
void sxepDiemht( ListSV DSSX)
{
    NodeSV *p;
    NodeSV *q;
    for( p= DSSX.Head; p->next !=NULL ; p=p->next)
    {
        for( q=p->next; q != NULL; q=q->next)
        {
            if(p->info.Diemht > q->info.Diemht)
            {
                SinhVien tmp= p->info;
                p->info=q->info;
                q->info=tmp;
            }
        }
    }
    indsSv(DSSX);

}
void inHoTenSV_DTB_min( ListSV &Q)
{
    NodeSV *p;
    float minDTB = Q.Head->info.Diemht ;
    for(p=Q.Head; p!=NULL; p = p->next)
    {
        if(minDTB > (p->info.Diemht))
        {
            minDTB = p->info.Diemht;
        }
    }

    cout<<"\nDiem TB nho nhat: "<<minDTB << " " ;

    for(p=Q.Head; p!=NULL; p = p -> next)
    {
        if((p ->info.Diemht)==minDTB)
        {
            cout<<setw(10)<<p->info.tenSV<<endl;
        }
    }
}
void luuFileDSSV(FILE *f, ListSV Q)
{
    f= fopen("DanhSachSV.dat", "w+b");
    int n=0;
    NodeSV *p;
    for(p=Q.Head; p!=NULL; p=p->next)
    {
        n=n+1;
    }
    fwrite(&n, sizeof(int),1,f);
    cout<< "\n GHi xong so phieu ban tru"<< endl;

    for(p=Q.Head; p!=NULL; p=p->next)
    {
        fwrite(&p->info, sizeof(SinhVien), 1,f);

    }
    fclose(f);
        cout<< "\n Ghi xong du cac phieu ban tru "<< endl;
}
void docFileDSSV( FILE *f, ListSV&Q)
{
    SinhVien x;
    int i,n;
    NodeSV *p;
    initSV(Q);
    f= fopen("DanhSachSV.dat","r+b");
    fread(&n, sizeof(int), 1,f);
    cout<< "\n So Phieu n= "<< n<< endl;

    for(i=0; i<n; i++)
    {
        fread(&x, sizeof(SinhVien),1,f);
        p = getNodeQLSV(x);
        chendauSV(Q,p);
    }
//while (fread(&x, sizeof(SinhVien), 1, f))
//	{
//
//		p=getNodeQLSV(x);
//		chendauSV(Q,p);
//	}
    indsSv(Q);
    fclose(f);

    cout<< "\n Doc file thanh cong"<< endl;

}
//void ghiFileGV(ListSV L, FILE* f)
//{
//		f = fopen("SinhVien.dat", "w+b");
//		NodeSV* p;
//		for ( p=L.Head; p!=NULL; p=p->next)
//		{
//			fwrite(&(p->info), sizeof(SinhVien), 1, f);
//		}
//		fclose(f);
//		cout << "Ghi file thanh cong!!";
//}
//void docFileGV(ListSV &L, FILE* f)
//{
//	f = fopen("SinhVien.dat", "r+b");
//	SinhVien x;
//	NodeSV* p;
//	initSV(L);
//	while (fread(&x, sizeof(SinhVien), 1, f))
//	{
//
//		p = getNodeQLSV(x);
//		chendauSV(L, p);
//	}
//	indsSv(QLSV);
//	fclose(f);
//	cout << "\nDoc file thanh cong.\n";
//}
int main()
{
    FILE *f;
//    nhapDSSV(QLSV);
//   indsSv(QLSV);
//ghiFileGV(QLSV,f); bỏ
//docFileGV(QLSV,f);bỏ
//     luuFileDSSV(f,QLSV);
     docFileDSSV(f,QLSV);
//         indsSv(QLSV);

// chỉ đọc đc file khi đang thực hiện chương trình, nếu chạy lại thì phải nhập lại

//Xoaptudau(QLSV);
//TimkiemMasv(QLSV);
//sxepDiemht(QLSV);
//inHoTenSV_DTB_min(QLSV);
    return 0;
}
