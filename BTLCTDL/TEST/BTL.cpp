#include<iostream>
#include<iomanip>
#include<string>
#include<cstdio>
#include<fstream>
using namespace std;
struct nhanVien {
	int maNv;
	string tenNv;
	string gt;
};
struct nodeNv {
	nhanVien nv;
	struct nodeNv* pNext;
};
nodeNv* khoiTaoNodeNv(nhanVien x) {
	nodeNv* p = new nodeNv;
	if (p == NULL) {
		return NULL;
	}
	p->nv = x;
	p->pNext = NULL;
	return p;
}
void nhapNv(nhanVien& x) {
	cin.ignore();
	cout << "\n Nhap ten: "; getline(cin, x.tenNv);
	cout << "\n Nhap ma: "; cin >> x.maNv;
	cin.ignore();
	cout << "\nNhap gioi tinh: "; getline(cin, x.gt);
}
void hienNv(nhanVien x) {
	cout << "\n Ten nhan vien tao phieu: " << x.tenNv;
	cout << "\n Ma so nhan vien: " << x.maNv;
	cout << "\n Gioi tinh: " << x.gt;
}
struct khachHang {
	int ma;
	string name;
	string sdt;
};
struct nodeKh {
	khachHang kh;
	struct nodeKh* pNext;
};
nodeKh* khoiTaoNodeKh(khachHang x) {
	nodeKh* p = new nodeKh;
	if (p == NULL) {
		return NULL;
	}
	p->kh = x;
	p->pNext = NULL;
	return p;
}
void nhapkH(khachHang& x) {
	cout << "\n Nhap ten: "; getline(cin, x.name);
	cout << "\n Nhap ma: "; cin >> x.ma;
	cin.ignore();
	cout << "\nNhap SDT: "; getline(cin, x.sdt);
}
void inKH(khachHang x) {
	cout << "\n Ten khach hang: " << x.name;
	cout << "\n Ma khach hang: " << x.ma;
	cout << "\n So dien thoai khach hang: " << x.sdt;
}
struct vatLieu {
	string tenVl;
	int maVl;
	float donGia;
	int soLuong;
	float thanhTien;
};

struct nodeVl {
	vatLieu vl;
	struct nodeVl* pNext;
};
struct listVl {
	nodeVl* pHead;
	nodeVl* pTail;
};
void KhoiTaoListVl(listVl& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
nodeVl* khoiTaoNodeVl(vatLieu x) {
	nodeVl* p = new nodeVl;
	if (p == NULL) {
		cout << "\n Het bo nho!";
		return NULL;
	}
	p->vl = x;
	p->pNext = NULL;
	return p;
}
void nhapVL(vatLieu& x) {
	cin.ignore();
	cout << "\n Nhap ten: "; getline(cin, x.tenVl);
	cout << "\n Nhap ma VL: "; cin >> x.maVl;
	cout << "\n Nhap don gia: "; cin >> x.donGia;
	cout << "\n Nhap so luong: "; cin >> x.soLuong;
	x.thanhTien = x.soLuong * x.donGia;
}
void inVL(vatLieu x) {
	cout << "\n"<<setw(16) << x.tenVl;
	cout << setw(16) << x.maVl;
	cout << setw(15) << x.donGia;
	cout << setw(10) << x.soLuong;
	cout << setw(15) << size_t(x.thanhTien);
}
void table() {
	cout << "\n"<<setw(16) << "Ten vat lieu";
	cout <<setw(16) << "Ma vat lieu";
	cout <<setw(15) << "Don gia";
	cout <<setw(10) << "So luong";
	cout <<setw(15) << "Thanh tien";

}
void chenDauVl(listVl& l, nodeVl* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void nhapDsVL(listVl& l) {
	int n;
	nodeVl* vl;
	vatLieu x;
	cout << "\n Nhap so vat lieu: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\n Vat lieu thu: " << i + 1;
		nhapVL(x);
		vl = khoiTaoNodeVl(x);
		chenDauVl(l, vl);
	}
}
void inDSVL(listVl l) {
	cout << "\n\t Danh sach cac vat lieu";
	table();
	for (nodeVl* p = l.pHead; p != NULL; p = p->pNext) {
		inVL(p->vl);
	}
}
struct date {
	int day;
	int month;
	int year;
};
struct phieuBan {
	nhanVien nv;
	date ngay;
	int maPh;
	khachHang kh;
	int sovl;
	listVl dsvl;
	float tongTien;
};
struct nodePhieuBan {
	phieuBan pb;
	struct nodePhieuBan* pNext;
};
struct listPhieuBan {
	nodePhieuBan* pHead;
	nodePhieuBan* pTail;
};
void khoiTaoListPhieu(listPhieuBan& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
nodePhieuBan* khoiTaonodePhieu(phieuBan& pb) {
	nodePhieuBan* p = new nodePhieuBan;
	if (p == NULL) {
		return NULL;
	}
	p->pb = pb;
	p->pNext = NULL;
	return p;
}
void nhapPhieu(phieuBan& x) {
	cout << "\nNhap ngay: "; cin >> x.ngay.day;
	cout << "\n Nhap thang: "; cin >> x.ngay.month;
	cout << "\nNhap nam: "; cin >> x.ngay.year;
	cout << "\n Nhap ma phieu: "; cin >> x.maPh;
	cout << "\n\t Nhap nhan vien lam phieu: ";
	nhapNv(x.nv);
	cout << "\n\tNhap thong tin khach hang ";
	nhapkH(x.kh);
	KhoiTaoListVl(x.dsvl);
	nhapDsVL(x.dsvl);
}
void inPhieu(phieuBan x) {
	listVl l;
	cout << "\n Ngay thang: " << x.ngay.day << "/" << x.ngay.month << "/" << x.ngay.year;
	cout << "\n Ma phieu: " << x.maPh;
	cout << "\n\t Thong tin nhan vien";
	hienNv(x.nv);
	cout << "\n\t Thong tin khach hang";
	inKH(x.kh);
	inDSVL(x.dsvl);
}
void chenVaoDauPhieu(listPhieuBan& l, nodePhieuBan* q) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = q;
	}
	else {
		q->pNext = l.pHead;
		l.pHead = q;
	}
}
void nhapDSPhieuBan(listPhieuBan& l) {
	int n;
	phieuBan x;
	cout << "\nNhap so phieu ban: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\n Phieu ban thu: " << i + 1;
		nhapPhieu(x);
		nodePhieuBan* pb = khoiTaonodePhieu(x);
		chenVaoDauPhieu(l, pb);
	}
}
void inDsPhieuBan(listPhieuBan l) {
	cout << "\n\t DANH SACH CAC PHIEU DA DUOC TAO";
	int dem = 0;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		cout << "\n Phieu ban thu: " << dem + 1;
		inPhieu(k->pb);
	}
}
void ghiFileGV(listPhieuBan L, FILE* f)
{
		f = fopen("PhieuBan.dat", "w+b");
		for (nodePhieuBan* p = L.pHead; p != NULL; p = p->pNext)
		{
			fwrite(&(p->pb), sizeof(phieuBan), 1, f);
		}
		fclose(f);
		cout << "Ghi file thanh cong!!";
}
void docFileGV(listPhieuBan& L, FILE* f)
{
	f = fopen("PhieuBan.dat", "r+b");
	phieuBan x;
	nodePhieuBan* p;
	khoiTaoListPhieu(L);
	while (fread(&x, sizeof(phieuBan), 1, f))
	{

		p = khoiTaonodePhieu(x);
		chenVaoDauPhieu(L, p);
	}
	inDsPhieuBan(L);
	fclose(f);
	cout << "Doc file thanh cong.\n";
}


void menu(listPhieuBan& l) {
	int chon;
	FILE *f;
	while (true) {
		system("cls");
		cout << "\n\t     _______MENU_______";
		cout << "\n\t1. Nhap danh sach phieu ban";
		cout << "\n\t2. Hien danh sach phieu ban";
		cout << "\n\t3. Luu file";
		cout<<"\n\t4.Doc file va hien danh sach";
		cout << "\n Lua chon cua ban";
		cin >> chon;
		if (chon == 1) {
			nhapDSPhieuBan(l);
		}
		else if (chon == 2) {
			inDsPhieuBan(l);
			system("pause");
		}
		else if (chon == 3) {
			ghiFileGV(l, f);
			system("pause");
		}
		else if(chon==4) {
			docFileGV(l,f);
			system("pause");
		}
	}
}
int main() {
	listPhieuBan l;
	khoiTaoListPhieu(l);
	menu(l);
	return 0;
}
