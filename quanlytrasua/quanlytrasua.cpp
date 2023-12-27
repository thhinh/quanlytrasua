#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;
#define MAX 1000
//==================================== khởi tạo cấu trúc thông tin loại trà sữa và hóa đơn
// cấu trúc thông tin trà sữa 
struct TRASUA
{
	char MaTS[10];
	char TenTS[50];
	char LoaiTS[30];
	int GiaBan;
}typedef TraSua;
//cấu trúc thông tin các loại trà sữa
struct LOAITS
{
	char MaLoai[10];
	char TenLoai[50];
}typedef LoaiTraSua;
//cấu trúc thông tin Hóa Đơn
struct HOADON
{
	char Mahd[10];
	char NgayHd[12];
	char TenNV[30];
}typedef HoaDon;
//cấu trúc thông tin trà sữa
struct NodeTraSua
{
	TraSua data;
	NodeTraSua* next;
};
struct ListTraSua
{
	NodeTraSua* head;
	NodeTraSua* tail;
};
//cấu trúc thông tin Chi Tiết Hóa Đơn
struct CTHOADON
{
	char Mahd[10];
	char MaTS[10];
	int SoLuong;
	int Gia;
}typedef CTHoaDon;
// casu trúc danh sách liên kết cho chi tiết hóa đơn
struct NodeCTHoaDon
{
	CTHoaDon data;
	NodeCTHoaDon* next;
};
struct ListCTHoaDon
{
	NodeCTHoaDon* head;
	NodeCTHoaDon* tail;
};
//=========================================================Chi tiết hóa đơn
//khởi tạo danh sách chi tiết hóa đơn 
void InitListCTHoaDon(ListCTHoaDon& l)
{
	l.head = l.tail = NULL;
}

NodeCTHoaDon* CreateNodeCTHoaDon(CTHoaDon x)
{
	NodeCTHoaDon* p = new NodeCTHoaDon;
	if (p == NULL) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}
// kiểm tra chi tiết hóa đơn có rỗng không
bool isEmptyCTHoaDon(ListCTHoaDon l)
{
	if (l.head == NULL) return true;
	return false;
}
// thêm phần tử vào đầu danh sách chi tiết hóa đơn
void addHeadCTHoaDon(ListCTHoaDon& l, CTHoaDon x)
{
	NodeCTHoaDon* p = CreateNodeCTHoaDon(x);
	if (isEmptyCTHoaDon(l))
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
// thêm phần tử vào cuối danh sách chi tiết hóa đơn
void addTailCTHoaDon(ListCTHoaDon& l, CTHoaDon x)
{
	NodeCTHoaDon* p = CreateNodeCTHoaDon(x);
	if (isEmptyCTHoaDon(l))
		addHeadCTHoaDon(l, x);
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
// kích thước của danh sách chi tiết hóa đơn
int SizeListCTHoaDon(ListCTHoaDon l)
{
	NodeCTHoaDon* p = l.head;
	if (isEmptyCTHoaDon(l))
		return 0;
	int size = 0;
	do
	{
		size++;
		p = p->next;
	} while (p != NULL);
	return size;
}
//================================================= Hóa đơn
// cấu trúc danh sách liên kết cho hóa đơn
struct NodeHoaDon
{
	HoaDon data;
	NodeHoaDon* next;
};
struct ListHoaDon
{
	NodeHoaDon* head;
	NodeHoaDon* tail;
};
// khởi tạo danh sách hóa đơn
void InitListHoaDon(ListHoaDon& l)
{
	l.head = l.tail = NULL;
}

NodeHoaDon* CreateNodeHoaDon(HoaDon x)
{
	NodeHoaDon* p = new NodeHoaDon;
	if (p == NULL) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}
// kiểm tra hóa đơn có rỗng không

bool isEmptyHoaDon(ListHoaDon l)
{
	if (l.head == NULL) return true;
	return false;
}
// thêm một phần tử vào đầu hóa đơn

void addHeadHoaDon(ListHoaDon& l, HoaDon x)
{
	NodeHoaDon* p = CreateNodeHoaDon(x);
	if (isEmptyHoaDon(l))
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
// thêm 1 phần tử vào cuối hóa đơn

void addTailHoaDon(ListHoaDon& l, HoaDon x)
{
	NodeHoaDon* p = CreateNodeHoaDon(x);
	if (isEmptyHoaDon(l))
		addHeadHoaDon(l, x);
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
// kích thước hóa đơn

int SizeListHoaDon(ListHoaDon l)
{
	NodeHoaDon* p = l.head;
	if (isEmptyHoaDon(l))
		return 0;
	int size = 0;
	do
	{
		size++;
		p = p->next;
	} while (p != NULL);
	return size;
}
//====================================== loại trà sữa
// cấu trúc liên kết các loại trà sữa 
struct NodeLoaiTraSua
{
	LoaiTraSua data;
	NodeLoaiTraSua* next;
};
struct ListLoaiTraSua
{
	NodeLoaiTraSua* head;
	NodeLoaiTraSua* tail;
};
// khởi tạo danh sách loại trà sữa 

void InitListLoaiTraSua(ListLoaiTraSua& l)
{
	l.head = l.tail = NULL;
}
// tạo node mới cho danh sách loại trà sữa 

NodeLoaiTraSua* CreateNodeLoaiTraSua(LoaiTraSua x)
{
	NodeLoaiTraSua* p = new NodeLoaiTraSua;
	if (p == NULL) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}
// kiểm tra danh sách loại trà sữa rỗng không

bool isEmptyLoaiTraSua(ListLoaiTraSua l)
{
	if (l.head == NULL) return true;
	return false;
}
// tạo kích thước cho danh sách trà sữa

int SizeListLoai(ListLoaiTraSua l)
{
	NodeLoaiTraSua* p = l.head;
	if (isEmptyLoaiTraSua(l))
		return 0;
	int size = 0;
	do
	{
		size++;
		p = p->next;
	} while (p != NULL);
	return size;
}
// thêm một phần tử vào đầu danh sách loại trà sữa 

void addHeadLoaiTraSua(ListLoaiTraSua& l, LoaiTraSua x)
{
	NodeLoaiTraSua* p = CreateNodeLoaiTraSua(x);
	if (isEmptyLoaiTraSua(l))
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
// thêm một phần tử vào cuối danh sách loại trà sữa

void addTailLoaiTraSua(ListLoaiTraSua& l, LoaiTraSua x)
{
	NodeLoaiTraSua* p = CreateNodeLoaiTraSua(x);
	if (isEmptyLoaiTraSua(l))
		addHeadLoaiTraSua(l, x);
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
//xóa một loại trà sữa theo mã loại

void DeleteMaLoaiTraSua(ListLoaiTraSua& l, char maloaitrasua[])
{
	if (isEmptyLoaiTraSua(l))
		return;
	if (strcmp(l.head->data.MaLoai, maloaitrasua) == 0)
	{
		if (l.head->next != NULL)
		{
			NodeLoaiTraSua* temp = l.head;
			l.head = l.head->next;
			delete temp;
			temp = NULL;
		}
		else
		{
			delete l.head;
			l.head = l.tail = NULL;
		}
	}
	else if (strcmp(l.tail->data.MaLoai, maloaitrasua) == 0)
	{
		NodeLoaiTraSua* temp = l.head;
		while (temp->next != l.tail)
			temp = temp->next;
		NodeLoaiTraSua* del = l.tail;
		delete del; del = NULL;
		l.tail = temp;
		l.tail->next = NULL;
	}
	else
	{
		NodeLoaiTraSua* temp = l.head;
		while (temp != NULL)
		{
			if (strcmp(temp->next->data.MaLoai, maloaitrasua) == 0)
				break;
			temp = temp->next;
		}
		if (temp->next != NULL)
		{
			NodeLoaiTraSua* del = temp->next;
			temp->next = del->next;
			delete del;
			del = NULL;
		}
	}
}
// tìm trà sữa theo mã loại

NodeLoaiTraSua* SearchMaLoaiTraSua(ListLoaiTraSua l, string maloaitrasua)
{
	NodeLoaiTraSua* p = l.head;
	if (isEmptyLoaiTraSua(l))
		return NULL;
	do
	{
		if (strcmp(p->data.MaLoai, maloaitrasua.c_str()) == 0)
			return p;
		else
			p = p->next;
	} while (p != NULL);
	return NULL;
}
//tìm loại trà sữa theo tên
NodeLoaiTraSua* SearchLoaiTraSuaTheoTen(ListLoaiTraSua l, string tenloaitrasua)
{
	NodeLoaiTraSua* p = l.head;
	if (isEmptyLoaiTraSua(l))
		return NULL;
	do
	{	
		// Chuyển tất cả sang kí tự thường
		char str1[50];
		for (int i = 0; i < strlen(p->data.TenLoai); i++) {
			str1[i] = tolower(p->data.TenLoai[i]);
		}
		str1[strlen(p->data.TenLoai)] = '\0'; // Chèn kí tự kết thúc chuỗi
		for (char& c : tenloaitrasua) {
			c = std::tolower(c);
		}
		if (strcmp(str1, tenloaitrasua.c_str()) == 0)
			return p;
		else
			p = p->next;
	} while (p != NULL);
	return NULL;
}
//Nhập thông tin cho 1 loại trà sữa mới

void Nhap1LoaiTraSua(ListLoaiTraSua l, LoaiTraSua& loaitrasua)
{
	do
	{
		cout << "Ma loai tra sua: ";
		cin >> loaitrasua.MaLoai;
		if (SearchMaLoaiTraSua(l, loaitrasua.MaLoai) == NULL)
			break;
		else
			cout << "Loai tra sua nay da ton tai, hay nhap lai!!!" << endl;
	} while (true);
	cout << "Ten loai tra sua: ";
	cin.ignore();
	cin.getline(loaitrasua.TenLoai, 50);
}
//cập nhật thông tin cho một loại trà sữa

void Update1LoaiTraSua(ListLoaiTraSua l)
{
	char maloai[10];
	int choice;
	NodeLoaiTraSua* loaitrasua = NULL;

	do
	{
		cout << "Ma loai tra sua: ";
		cin >> maloai;
		loaitrasua = SearchMaLoaiTraSua(l, maloai);
		if (loaitrasua != NULL)
			break;
		else
			cout << "Loai tra sua nay khong ton tai, hay nhap lai!!!" << endl;
	} while (true);
	do {
		cout << "\nBan muon sua gi?\n";
		cout << "1. Ma loai tra sua\n";
		cout << "2. Ten loai tra sua\n";
		cout << "0. Hoan tat cap nhat\n";
		cout << "Ban chon so:";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Ma loai tra sua: ";
			cin >> loaitrasua->data.MaLoai;
			break;
		case 2:
			cout << "Ten loai tra sua: ";
			cin.ignore();
			cin.getline(loaitrasua->data.TenLoai, 50);
			break;
		case 0:
			break;
			cout << "Cap nhat thanh cong" << endl;
		default:
			cout << "Khong co chuc nang nay\n";
			break;
		}
	} while (choice != 0);
}
//xuất danh sách các loại trà sữa bao gồm mã loại và tên loại
void Xuat1LoaiTraSua(LoaiTraSua loaitrasua)// xuat ra bang cac loai tra sua
{
	cout << "|" << setw(17) << loaitrasua.MaLoai << "|" << setw(26) << loaitrasua.TenLoai << "|" << endl;
}
//nhập thông tin về danh sách loại Trà Sữa, số lượng,thông tin chi tiết về từng loại bằng cách gọi hàm Nhap1LoaiTraSua và thêm vào danh sách

void NhapDanhSachLoaiTraSua(ListLoaiTraSua& l)//nhập bảng trà sữa
{
	int n;
	cout << "Nhap so luong loai tra sua: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		LoaiTraSua loaitrasua;
		cout << "Nhap thong tin loai tra sua thu " << i + 1 << endl;
		Nhap1LoaiTraSua(l, loaitrasua);
		addTailLoaiTraSua(l, loaitrasua);
		cout << endl;

	}
}
//xuất ra màn hình thông tin chi tiết về toàn bộ danh sách loại Trà Sữa sử dụng hàm Xuat1LoaiTraSua để xuất thông tin của từng loại
void XuatDanhSachLoaiTraSua(ListLoaiTraSua& l) // xuat danh sach loai tra sua 
{
	if (isEmptyLoaiTraSua(l))
		return;
	cout << "-------------DANH SACH LOAI TRA SUA-----------" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "|     Ma loai     |     Ten loai tra sua     |" << endl;
	cout << "----------------------------------------------" << endl;
	NodeLoaiTraSua* p = l.head;
	for (NodeLoaiTraSua* p = l.head; p != NULL; p = p->next)
	{
		Xuat1LoaiTraSua(p->data);
	}
	cout << "----------------------------------------------" << endl;
}
//Xoá trà sữa cùng loại
void DeleteTSCungLoai(ListTraSua& l, char loaitrasua[])
{
	if (l.head == NULL)// kiểm tra danh sách có rỗng hay không
		return;
	if (strcmp(l.head->data.LoaiTS, loaitrasua) == 0)// kiểm tra xóa đầu danh sách
	{
		if (l.head->next != NULL)// nếu danh sách có nhiều hơn một node
		{
			NodeTraSua* temp = l.head;
			l.head = l.head->next;
			delete temp;
			temp = NULL;
		}
		else// nếu danh sách chỉ có 1 node
		{
			delete l.head;
			l.head = l.tail = NULL;
		}
	}
	else if (strcmp(l.tail->data.LoaiTS, loaitrasua) == 0)// kiểm tra xóa cuối danh sách
	{
		NodeTraSua* temp = l.head;
		while (temp->next != l.tail)
			temp = temp->next;
		NodeTraSua* del = l.tail;
		delete del; del = NULL;
		l.tail = temp;
		l.tail->next = NULL;
	}
	else// kiểm tra xóa giữa danh sách
	{
		NodeTraSua* temp = l.head;
		while (temp != NULL)
		{
			if (strcmp(temp->data.LoaiTS, loaitrasua) == 0)
				break;
			temp = temp->next;
		}
		if (temp != NULL)//nếu node cần xóa ở giữa danh sách
		{
			NodeTraSua* del = temp->next;
			temp->next = del->next;
			delete del;
			del = NULL;
		}
	}
}
//xóa một loại Trà Sữa khỏi danh sách bằng cách nhập mã loại cần xóa và sử dụng hàm DeleteMaLoaiTraSua
void XoaLoaiTraSua(ListLoaiTraSua& l, ListTraSua &listTraSua)//xóa loại trà 
{
	char ma[10];
	XuatDanhSachLoaiTraSua(l);
	cout << endl;
	cout << "Nhap ma loai tra sua can xoa: ";
	cin >> ma;
	if (SearchMaLoaiTraSua(l, ma) == NULL)
	{
		cout << "Khong ton tai loai tra sua nao co ma la: " << ma << endl;
	}
	else
	{	
		do {
		char YesNo;
		cout << "\nBan co muon cac tra sua cung loai hay khong? (Y/N): ";
		cin >> YesNo;
		if (YesNo == 'Y' || YesNo == 'y') {
			NodeTraSua* temp = listTraSua.head;
			while (temp != NULL) {
				DeleteTSCungLoai(listTraSua, ma);
				temp = temp->next;
			}
				DeleteMaLoaiTraSua(l, ma);
				cout << "Xoa loai tra sua thanh cong" << endl;
		}
		else {
			cout << "\nBan da chon khong xoa";
		}
			break;
		} while (true);
		//DeleteMaLoaiTraSua(l,ma);
	}
}
// dùng để tìm kiếm loại Trà Sữa theo tên mà người dùng nhập tên loại và xuất ra thông tin của loại Trà Sữa đó

void TimKiemLoaiTraSuaTheoTen(ListLoaiTraSua l)
{
	char tenTS[50];
	cout << "\nNhap ten loai tra sua de tim: ";
	cin.ignore();
	cin.getline(tenTS, 50);
	NodeLoaiTraSua* trasua = SearchLoaiTraSuaTheoTen(l, tenTS);
	if (trasua != NULL)
	{
		cout << "-------------DANH SACH LOAI TRA SUA-----------" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "|     Ma loai     |     Ten loai tra sua     |" << endl;
		cout << "----------------------------------------------" << endl;
		Xuat1LoaiTraSua(trasua->data);

		cout << "----------------------------------------------" << endl;
	}
	else
		cout << "Khong tim thay loai tra sua co ten la: " << trasua << endl;
}


//-------------------------Cấu trúc trà sữa và chức năng

void InitListTraSua(ListTraSua& l)
{
	l.head = l.tail = NULL;
}

NodeTraSua* CreateNodeTraSua(TraSua x)
{
	NodeTraSua* p = new NodeTraSua;
	if (p == NULL) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}
//kiểm tra danh sách liên kết có trống hay không
bool isEmptyTraSua(ListTraSua l)
{
	if (l.head == NULL) return true;
	return false;
}
// kích thước danh sách
int SizeListTraSua(ListTraSua l)
{
	if (isEmptyTraSua(l))
		return 0;
	NodeTraSua* p = l.head;
	int size = 0;
	do
	{
		size++;
		p = p->next;
	} while (p != NULL);
	return size;
}
// thêm phần tử vào đầu danh sách
void addHead(ListTraSua& l, TraSua x)
{
	NodeTraSua* p = CreateNodeTraSua(x);
	if (isEmptyTraSua(l))
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
// thêm phần tử vào cuối danh sách
void addTail(ListTraSua& l, TraSua x)
{
	NodeTraSua* p = CreateNodeTraSua(x);
	if (isEmptyTraSua(l))
		addHead(l, x);
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
//xóa một node từ danh sách liên kết đơn dựa trên mã trà sữa
void DeleteMaTS(ListTraSua& l, char matrasua[])
{
	if (isEmptyTraSua(l))// kiểm tra danh sách có rỗng hay không
		return;
	if (strcmp(l.head->data.MaTS, matrasua) == 0)// kiểm tra xóa đầu danh sách
	{
		if (l.head->next != NULL)// nếu danh sách có nhiều hơn một node
		{
			NodeTraSua* temp = l.head;
			l.head = l.head->next;
			delete temp;
			temp = NULL;
		}
		else// nếu danh sách chỉ có 1 node
		{
			delete l.head;
			l.head = l.tail = NULL;
		}
	}
	else if (strcmp(l.tail->data.MaTS, matrasua) == 0)// kiểm tra xóa cuối danh sách
	{
		NodeTraSua* temp = l.head;
		while (temp->next != l.tail)
			temp = temp->next;
		NodeTraSua* del = l.tail;
		delete del; del = NULL;
		l.tail = temp;
		l.tail->next = NULL;
	}
	else// kiểm tra xóa giữa danh sách
	{
		NodeTraSua* temp = l.head;
		while (temp != NULL)
		{
			if (strcmp(temp->next->data.MaTS, matrasua) == 0)
				break;
			temp = temp->next;
		}
		if (temp->next != NULL)//nếu node cần xóa ở giữa danh sách
		{
			NodeTraSua* del = temp->next;
			temp->next = del->next;
			delete del;
			del = NULL;
		}
	}
}
// tìm kiếm node trong danh sách liên kết
NodeTraSua* SearchMaTraSua(ListTraSua l, string matrasua)
{
	NodeTraSua* p = l.head;
	if (isEmptyTraSua(l))
		return NULL;
	do
	{
		if (strcmp(p->data.MaTS, matrasua.c_str()) == 0)
			return p;
		else
			p = p->next;
	} while (p != NULL);
	return NULL;
}
// tìm kiếm node theo danh sách tên trà sữa
NodeTraSua* SearchTraSuaTheoTen(ListTraSua l, string tentrasua)
{
	NodeTraSua* p = l.head;
	if (isEmptyTraSua(l))
		return NULL;
	do
	{	
		// Chuyển tất cả sang kí tự thường
		char str1[50];
		for (int i = 0; i < strlen(p->data.TenTS); i++) {
			str1[i] = tolower(p->data.TenTS[i]);
		}
		str1[strlen(p->data.TenTS)] = '\0';
		for (char& c : tentrasua) {
			c = std::tolower(c);
		}
		//So sanh chuoi
		if (strcmp(str1, tentrasua.c_str()) == 0)
			return p;
		else
			p = p->next;
	} while (p != NULL);
	return NULL;
}
// nhập trà trà sữa
void Nhap1TraSua(ListTraSua l, ListLoaiTraSua loai, TraSua& trasua)
{
	do
	{
		cout << "Ma tra sua: ";
		cin >> trasua.MaTS;
		if (SearchMaTraSua(l, trasua.MaTS) == NULL)// kiểm tra xem mã đã tồn tại chưa
			break;
		else
			cout << "Tra sua nay da ton tai, hay nhap lai!!!" << endl;
	} while (true);
	cout << "Ten tra sua: ";
	cin.ignore();// bỏ ký tự /n
	cin.getline(trasua.TenTS, 50);
	XuatDanhSachLoaiTraSua(loai);// xuất danh sách các loại trà
	do
	{
		cout << "Loai tra sua: ";
		cin >> trasua.LoaiTS;
		if (SearchMaLoaiTraSua(loai, trasua.LoaiTS) != NULL)
			break;
		else
			cout << "Loai tra sua nay khong dung, hay nhap lai!!!" << endl;
	} while (true);
	cout << "Gia ban: ";
	cin >> trasua.GiaBan;
}
// cập nhật thông tin đối tượng đã tồn tại trong danh sách
void Update1TraSua(ListTraSua l, ListLoaiTraSua loai)
{
	NodeTraSua* trasua = NULL;
	do
	{
		char mats[10];
		cout << "Ma tra sua de cap nhat: ";
		cin >> mats;
		trasua = SearchMaTraSua(l, mats);// tìm kiếm trà sữa theo mã
		if (trasua != NULL)
			break;
		else
			cout << "Tra sua nay khong ton tai, hay nhap lai!!!" << endl;
	} while (true);
	int choice;
	do {
		cout << "\nBan muon sua gi?\n";
		cout << "1. Ma tra sua\n";
		cout << "2. Ten tra sua\n";
		cout << "3. Loai tra sua\n";
		cout << "4. Gia ban\n";
		cout << "0. Hoan tat cap nhat\n";
		cout << "Ban chon so:";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Ma tra sua: ";
			cin >> trasua->data.MaTS;
			break;
		case 2:
			cout << "Ten tra sua: ";
			cin.ignore();
			cin.getline(trasua->data.TenTS, 50);
			break;
		case 3:
			XuatDanhSachLoaiTraSua(loai);
			do
			{
				cout << "Loai tra sua: ";
				cin >> trasua->data.LoaiTS;
				if (SearchMaLoaiTraSua(loai, trasua->data.LoaiTS) != NULL)// kiểm tra xem loại trà sữa có tồn tại hay không
					break;
				else
					cout << "Loai tra sua nay khong dung, hay nhap lai!!!" << endl;
			} while (true);
			break;
		case 4:
			cout << "Gia ban: ";
			cin >> trasua->data.GiaBan;
			break;
		case 0:
			break;
			cout << "Cap nhat thanh cong" << endl;
		default:
			cout << "Khong co chuc nang nay\n";
			break;
		}
	} while (choice != 0);
}
// xuất ra màn hình 
void Xuat1TraSua(TraSua trasua)
{
	cout << "|" << setw(20) << trasua.MaTS << "|" << setw(21) << trasua.TenTS << "|" << setw(14) << trasua.LoaiTS << "|" << setw(15) << trasua.GiaBan << "|";
}
// nhập danh sách trà sữa
void NhapDanhSachTraSua(ListTraSua& l, ListLoaiTraSua loai)
{
	int n;
	cout << "Nhap so luong tra sua: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		TraSua trasua;
		cout << "Nhap thong tin tra sua thu " << i + 1 << endl;
		Nhap1TraSua(l, loai, trasua);// gọi hàm Nhap1TraSua để nhập thông tin của 1 trà sữa
		addTail(l, trasua);// thêm trà sữa vào danh sách sau khi nhập
		cout << endl;

	}
}
// hàm xuất trà sữa
void XuatDanhSachTraSua(ListTraSua& l)
{
	if (isEmptyTraSua(l))
		return;
	cout << "-------------------------------DANH SACH TRA SUA---------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "|     Ma tra sua     |     Ten tra sua     |     Loai     |    Gia ban    |" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	NodeTraSua* p = l.head;
	for (NodeTraSua* p = l.head; p != NULL; p = p->next)
	{
		Xuat1TraSua(p->data);
		cout << endl;
	}
	cout << "---------------------------------------------------------------------------" << endl;
}
//hàm xóa trà sữa
void XoaTraSua(ListTraSua& l)
{
	char ma[10];
	XuatDanhSachTraSua(l);// xuất danh sách để chọn mã cần xóa
	cout << endl;
	cout << "Nhap ma tra sua can xoa: ";
	cin >> ma;
	if (SearchMaTraSua(l, ma) == NULL)// tìm kiếm có mã trà sữa nào tồn tại hay không
	{
		cout << "Khong ton tai tra sua nao co ma la: " << ma << endl;
	}
	else
	{
		DeleteMaTS(l, ma);//nếu có mã tồn tại thì dùng hàm DeleteMaTS để xóa đi
		cout << "Xoa tra sua thanh cong" << endl;
	}
}
// tìm kiếm trà sữa theo tên
void TimKiemTraSuaTheoTen(ListTraSua l)
{
	char tenTS[50];
	cout << "\nNhap ten tra sua de tim: ";
	cin.ignore();
	cin.getline(tenTS, 50);
	NodeTraSua* trasua = SearchTraSuaTheoTen(l, tenTS);
	if (trasua != NULL)
	{
		cout << "-------------------------------DANH SACH TRA SUA---------------------------" << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "|     Ma tra sua     |     Ten tra sua     |     Loai     |    Gia ban    |" << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		Xuat1TraSua(trasua->data);
		cout << endl;
		cout << "---------------------------------------------------------------------------" << endl;
	}
	else
		cout << "Khong tim thay tra sua co ten la: " << trasua << endl;
}
// hàm dùng để xác nhận muốn tiếp tục hay không
bool XacNhan()
{
	char YesNo;
	cout << "Ban co muon tiep tuc(Y/N): ";
	cin >> YesNo;
	if (YesNo == 'Y' || YesNo == 'y')
		return true;
	return false;
}
//tìm kiếm đối tượng có trong danh sách đưa vào Mahd
NodeHoaDon* SearchMaHoaDon(ListHoaDon l, string mahd)
{
	NodeHoaDon* p = l.head;
	if (isEmptyHoaDon(l))//kiểm tra danh sách có rỗng hay không
		return NULL;
	do// tìm qua danh sách để tìm theo mã hóa đơn
	{
		if (strcmp(p->data.Mahd, mahd.c_str()) == 0)
			return p;// nếu có trả về con trỏ có node chứa hóa đơn đó 
		else
			p = p->next;
	} while (p != NULL);// trả về null nếu không có mã hóa đơn trong danh sách 
	return NULL;
}
int maHDLonNhat(ListHoaDon l) {
	int max = 0;
	while (l.head != NULL) {
		char* output;
		int Mahd = strtol(l.head->data.Mahd, &output, 10);
		if (Mahd > max) {
			max = Mahd;
		}
		l.head = l.head->next;
	}
	return max;
}
// tạo một hóa đơn và thêm vào danh sách hóa đơn
HoaDon TaoHoaDon(ListHoaDon& l, int& status)
{
	HoaDon hoadon;
	do
	{	
		int mahd = maHDLonNhat(l) + 1;
		sprintf(hoadon.Mahd, "%d", mahd);
		NodeHoaDon* hd = SearchMaHoaDon(l, hoadon.Mahd);// kiểm tra mã hóa đơn đã tồn tại hay chưa
		if (hd == NULL)
		{	
			// Lấy ngày hiện tại
			time_t t = time(0);
			struct tm* now = localtime(&t);
			int currentDay = now->tm_mday;
			int currentMonth = now->tm_mon + 1; // Tháng bắt đầu từ 0
			int currentYear = now->tm_year + 1900; // Năm hiện tại
			strftime(hoadon.NgayHd, sizeof(hoadon.NgayHd), "%d/%m/%Y", now);
			cout << "Ten nhan vien: ";
			cin.ignore();
			cin.getline(hoadon.TenNV, 30);
			status = 1;
			addTailHoaDon(l, hoadon);// thêm một hóa đơn vào danh sách
			break;
		}
		else
		{
			cout << "Hoa don da ton tai, hay nhap lai..." << endl;
			if (XacNhan() == false)// nếu người dùng không muốn nhập lại
			{
				break;
			}
		}
	} while (true);
	return hoadon;
}
// thực hiện quy trình bán trà sữa, tạo hóa đơn, thêm các chi tiết vài hóa đơn
void BanTraSua(ListTraSua l, ListHoaDon& listhoadon, ListCTHoaDon& listCThoadon)
{
	HoaDon hd;
	int status = 0;
	hd = TaoHoaDon(listhoadon, status);//tạo hóa đơn
	if (status == 1)//nếu status = 1 thì tiếp tục công việc bán trà sữa, nếu khác 1 thì báo lỗi và kết thúc
	{
		do// dùng vòng lặp để có thể thêm nhiều sản phẩm sau khi nhập số lượng
		{
			XuatDanhSachTraSua(l);
			char MaTS[10];
			cout << "Ma tra sua: ";
			cin >> MaTS;
			int soluongtrasua = 0;
			NodeTraSua* trasua = SearchMaTraSua(l, MaTS);
			if (trasua == NULL)
			{
				cout << "Ma tra sua khong ton tai." << endl;
			}
			else
			{
				CTHoaDon cthd;
				cout << "Nhap so luong:";
				cin >> cthd.SoLuong;
				strcpy(cthd.MaTS, trasua->data.MaTS);
				strcpy(cthd.Mahd, hd.Mahd);
				cthd.Gia = trasua->data.GiaBan;
				addTailCTHoaDon(listCThoadon, cthd);
			}
			if (XacNhan() == false)
				break;
		} while (true);
		long thanhtien = 0;
		cout << "| Ma Hoa Don: " << hd.Mahd << endl;
		cout << "| Ten Nhan Vien: " << hd.TenNV << endl;
		cout << "| Date: " << hd.NgayHd << endl;
		cout << "|--------------------------------Hoa don-----------------------------|---------------------|" << endl;
		cout << "|  No  |         San Pham           |  So Luong  |      Gia Tien     |      Thanh tien     |" << endl;
		cout << "|--------------------------------------------------------------------|---------------------|" << endl;
		int i = 1;
		for (NodeCTHoaDon* p = listCThoadon.head; p != NULL; p = p->next)
		{
			if (strcmp(p->data.Mahd, hd.Mahd) == 0 && SearchMaTraSua(l, p->data.MaTS) !=NULL)
			{
				NodeTraSua* trasua = SearchMaTraSua(l, p->data.MaTS);
				cout << "|" << setw(6) << (i++) << "|" << setw(28) << trasua->data.TenTS << "|" << setw(12) << p->data.SoLuong << "|" << setw(19) << p->data.Gia << "|" << setw(21) << p->data.Gia * p->data.SoLuong << "|" << endl;
				thanhtien += p->data.Gia * p->data.SoLuong;
			}
		}
		cout << "|------------------------------------------------------------------------------------------|" << endl;
		cout << "Tong: " << thanhtien << endl;
	}
}
// nhập và tìm kiếm hóa đơn đã bán của người dùng theo mã
void TimHoaDonTheoMa(ListHoaDon listHoaDon, ListCTHoaDon listCTHoaDon, ListTraSua listTraSua)
{
	if (isEmptyHoaDon(listHoaDon) || isEmptyCTHoaDon(listCTHoaDon))
	{
		cout << "Danh sach hoa don dang trong" << endl;
		return;
	}
	char mahd[10];
	do
	{
		cout << "Nhap ma hoa don: ";
		cin >> mahd;
		NodeHoaDon* hd = SearchMaHoaDon(listHoaDon, mahd);

		if (hd == NULL)
		{
			cout << "Khong tim thay hoa don nay...";
			if (XacNhan() == false)
				break;
		}
		else
		{
			long thanhtien = 0;
			cout << "| Ma Hoa Don: " << hd->data.Mahd << endl;
			cout << "| Ten Nhan Vien: " << hd->data.TenNV << endl;
			cout << "| date: " << hd->data.NgayHd << endl;
			cout << "|--------------------------------Hoa don-----------------------------|---------------------|" << endl;
			cout << "|  No  |         San Pham           |  So Luong  |      Gia Tien     |      Thanh tien     |" << endl;
			cout << "|--------------------------------------------------------------------|---------------------|" << endl;
			int i = 0;
			for (NodeCTHoaDon* p = listCTHoaDon.head; p != NULL; p = p->next)
			{
				if (strcmp(p->data.Mahd, hd->data.Mahd) == 0)
				{
					if (SearchMaTraSua(listTraSua, p->data.MaTS) != NULL) {
					NodeTraSua* trasua = SearchMaTraSua(listTraSua, p->data.MaTS);
					cout << "|" << setw(6) << (i + 1) << "|" << setw(28) << trasua->data.TenTS << "|" << setw(12) << p->data.SoLuong << "|" << setw(19) << p->data.Gia << "|" << setw(21) << p->data.Gia * p->data.SoLuong << "|" << endl;
					thanhtien += p->data.Gia * p->data.SoLuong;
					i++;
					}
					else {
					cout << "|Tra sua nay khong con ton tai trong he thong!!" << endl;
					}
				}
			}
			cout << "|------------------------------------------------------------------------------------------|" << endl;
			cout << "Tong: " << thanhtien << endl;
			break;
		}
	} while (true);
}
//Thống kê doanh thu theo ngày
void ThongKeDoanhThuTheoNgay(ListHoaDon listHoaDon, ListCTHoaDon listCTHoaDon, ListTraSua listTraSua)
{
	if (isEmptyHoaDon(listHoaDon) || isEmptyCTHoaDon(listCTHoaDon))
	{
		cout << "Danh sach hoa don dang trong" << endl;
		return;
	}
	char ngayThongKe[12];
	do
	{	
		bool isFound = false;
		int tongDoanhThuTrongNgay = 0;
		cout << "Nhap ngay can thong ke doanh thu: ";
		cin >> ngayThongKe;
		int dayFound, monthFound, yearFound;
		sscanf(ngayThongKe, "%d/%d/%d", &dayFound, &monthFound, &yearFound);
		NodeHoaDon* p = listHoaDon.head;
		while (p != NULL) {
			// Trích xuất ngày tháng năm từ chuỗi
			int day, month, year;
			sscanf(p->data.NgayHd, "%d/%d/%d", &day, &month, &year);
			if (day == dayFound && month == monthFound && year == yearFound) {
				isFound = true;
				long thanhtien = 0;
				cout << "| Ma Hoa Don: " << p->data.Mahd << endl;
				cout << "| Ten Nhan Vien: " << p->data.TenNV << endl;
				cout << "| date: " << p->data.NgayHd << endl;
				cout << "|--------------------------------Hoa don-----------------------------|---------------------|" << endl;
				cout << "|  No  |         San Pham           |  So Luong  |      Gia Tien     |      Thanh tien     |" << endl;
				cout << "|--------------------------------------------------------------------|---------------------|" << endl;
				int index = 0;
				for (NodeCTHoaDon* i = listCTHoaDon.head; i != NULL; i = i->next)
				{
					if (strcmp(i->data.Mahd, p->data.Mahd) == 0)
					{
						if (SearchMaTraSua(listTraSua, i->data.MaTS) != NULL) {
							NodeTraSua* trasua = SearchMaTraSua(listTraSua, i->data.MaTS);
							cout << "|" << setw(6) << (index + 1) << "|" << setw(28) << trasua->data.TenTS << "|" << setw(12) << i->data.SoLuong << "|" << setw(19) << i->data.Gia << "|" << setw(21) << i->data.Gia * i->data.SoLuong << "|" << endl;
							thanhtien += i->data.Gia * i->data.SoLuong;
							index++;
						}
						else {
							cout << "|Tra sua nay khong con ton tai trong he thong!!" << endl;
						}
					}
				}
				cout << "|------------------------------------------------------------------------------------------|" << endl;
				cout << "Tong: " << thanhtien << endl;
				tongDoanhThuTrongNgay += thanhtien;
			}
			p = p->next;
		}

		if (isFound == false)
		{
			cout << "Khong tim thay hoa don nao trong ngay de thong ke doanh thu...";
			if (XacNhan() == false)
				break;
		}
		cout << "Tong doanh thu cua ngay " << ngayThongKe << " la: " << tongDoanhThuTrongNgay;
		break;
	} while (true);
}
//Thống kê doanh thu theo tháng
void ThongKeDoanhThuTheoThang(ListHoaDon listHoaDon, ListCTHoaDon listCTHoaDon, ListTraSua listTraSua)
{
	if (isEmptyHoaDon(listHoaDon) || isEmptyCTHoaDon(listCTHoaDon))
	{
		cout << "Danh sach hoa don dang trong" << endl;
		return;
	}
	char thangThongKe[12];
	do
	{
		bool isFound = false;
		int tongDoanhThuTrongThang = 0;
		cout << "Nhap thang can thong ke doanh thu: ";
		cin >> thangThongKe;
		int monthFound, yearFound;
		sscanf(thangThongKe, "%d/%d", &monthFound, &yearFound);
		NodeHoaDon* p = listHoaDon.head;
		while (p != NULL) {
			// Trích xuất ngày tháng năm từ chuỗi
			int day, month, year;
			sscanf(p->data.NgayHd, "%d/%d/%d", &day, &month, &year);
			if (month == monthFound && year == yearFound) {
				isFound = true;
				long thanhtien = 0;
				cout << "| Ma Hoa Don: " << p->data.Mahd << endl;
				cout << "| Ten Nhan Vien: " << p->data.TenNV << endl;
				cout << "| date: " << p->data.NgayHd << endl;
				cout << "|--------------------------------Hoa don-----------------------------|---------------------|" << endl;
				cout << "|  No  |         San Pham           |  So Luong  |      Gia Tien     |      Thanh tien     |" << endl;
				cout << "|--------------------------------------------------------------------|---------------------|" << endl;
				int index = 0;
				for (NodeCTHoaDon* i = listCTHoaDon.head; i != NULL; i = i->next)
				{
					if (strcmp(i->data.Mahd, p->data.Mahd) == 0)
					{
						if (SearchMaTraSua(listTraSua, i->data.MaTS) != NULL) {
							NodeTraSua* trasua = SearchMaTraSua(listTraSua, i->data.MaTS);
							cout << "|" << setw(6) << (index + 1) << "|" << setw(28) << trasua->data.TenTS << "|" << setw(12) << i->data.SoLuong << "|" << setw(19) << i->data.Gia << "|" << setw(21) << i->data.Gia * i->data.SoLuong << "|" << endl;
							thanhtien += i->data.Gia * i->data.SoLuong;
							index++;
						}
						else {
							cout << "|Tra sua nay khong con ton tai trong he thong!!" << endl;
						}
					}
				}
				cout << "|------------------------------------------------------------------------------------------|" << endl;
				cout << "Tong: " << thanhtien << endl;
				tongDoanhThuTrongThang += thanhtien;
			}
			p = p->next;
		}

		if (isFound == false)
		{
			cout << "Khong tim thay hoa don nao trong ngay de thong ke doanh thu...";
			if (XacNhan() == false)
				break;
		}
		cout << "Tong doanh thu cua thang " << thangThongKe << " la: " << tongDoanhThuTrongThang;
		break;
	} while (true);
}
// ghi thông tin về các mục trà sữa
void GhiTraSuaVaoFile(ListTraSua l)
{
	if (isEmptyTraSua(l))
		return;
	ofstream fout("DanhSachTraSua.txt");// mở file txt để lưu thông tin
	fout << SizeListTraSua(l) << endl;// ghi số lượng trà sữa vào file txt
	NodeTraSua* p = l.head;
	int size = 0;
	do
	{
		fout << p->data.MaTS << endl;
		fout << p->data.TenTS << endl;
		fout << p->data.LoaiTS << endl;
		fout << p->data.GiaBan << endl;
		p = p->next;
	} while (p != NULL);
	fout.close();
}
// ghi thông tin về các loại trà sữa
void GhiLoaiTraSuaVaoFile(ListLoaiTraSua l)
{
	if (isEmptyLoaiTraSua(l))
		return;
	ofstream fout("DanhSachLoaiTraSua.txt");// mở file txt để lưu thông tin
	fout << SizeListLoai(l) << endl;// ghi số lượng loại trà sữa vào file txt
	NodeLoaiTraSua* p = l.head;
	int size = 0;
	do
	{
		fout << p->data.MaLoai << endl;
		fout << p->data.TenLoai << endl;
		p = p->next;
	} while (p != NULL);
	fout.close();
}
// ghi thông tin về hóa đơn

void GhiHoaDonVaoFile(ListHoaDon l)
{
	if (isEmptyHoaDon(l))
		return;
	ofstream fout("DanhSachHoaDon.txt");// mở file txt để lưu thông tin 
	fout << SizeListHoaDon(l) << endl;// ghi số lượng hóa đơn vào file
	NodeHoaDon* p = l.head;
	int size = 0;
	do
	{
		fout << p->data.Mahd << endl;
		fout << p->data.NgayHd << endl;
		fout << p->data.TenNV << endl;
		p = p->next;
	} while (p != NULL);
	fout.close();
}
// ghi chi tiết thông tin hóa đơn vào file

void GhiChiTietHoaDonVaoFile(ListCTHoaDon l)
{
	if (isEmptyCTHoaDon(l))
		return;
	ofstream fout("DanhSachChiTietHoaDon.txt");
	fout << SizeListCTHoaDon(l) << endl;
	NodeCTHoaDon* p = l.head;
	int size = 0;
	do
	{
		fout << p->data.Mahd << endl;
		fout << p->data.MaTS << endl;
		fout << p->data.SoLuong << endl;
		fout << p->data.Gia << endl;
		p = p->next;
	} while (p != NULL);
	fout.close();
}
void LoadTraSuaTuFile(ListTraSua& l)
{
	ifstream fin("DanhSachTraSua.txt");
	if (fin.is_open())//kiem tra mo file thanh cong hay khong
	{
		int n = 0;
		fin >> n;
		string line;
		stringstream ss;
		std::getline(fin, line);//doc file theo dong
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, line);
			TraSua trasua;
			strcpy(trasua.MaTS, line.c_str());

			std::getline(fin, line);
			strcpy(trasua.TenTS, line.c_str());

			std::getline(fin, line);
			strcpy(trasua.LoaiTS, line.c_str());

			std::getline(fin, line);
			ss << line;//Dung ham nay do chuyen doi tu kieu chuoi sang kieu so nguyen
			ss >> trasua.GiaBan;
			ss.clear();//su dung xong clear no di de lan sau su dung lai
			addTail(l, trasua);
		}
	}
	fin.close();//sau do dong file lai
}
void LoadLoaiTraSuaTuFile(ListLoaiTraSua& l)
{
	ifstream fin("DanhSachLoaiTraSua.txt");
	if (fin.is_open())//kiem tra mo file thanh cong hay khong
	{
		int n = 0;
		fin >> n;
		string line;
		stringstream ss;
		std::getline(fin, line);//doc file theo dong
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, line);
			LoaiTraSua loai;
			strcpy(loai.MaLoai, line.c_str());

			std::getline(fin, line);
			strcpy(loai.TenLoai, line.c_str());
			addTailLoaiTraSua(l, loai);
		}
	}
	fin.close();//sau do dong file lai
}
//đọc danh sách hóa đơn
void LoadHoaDonTuFile(ListHoaDon& l)
{
	ifstream fin("DanhSachHoaDon.txt");//mở file để đọc dữ liệu
	if (fin.is_open())//kiểm tra mở file thành công hay không
	{
		int n = 0;
		fin >> n;//đọc số lượng mở file
		string line;
		stringstream ss;
		std::getline(fin, line);//đọc file theo dòng
		for (int i = 0; i < n; i++)
		{   //đọc mã hóa đơn
			std::getline(fin, line);
			HoaDon hd;
			strcpy(hd.Mahd, line.c_str());
			//đọc ngày hóa đơn
			std::getline(fin, line);
			strcpy(hd.NgayHd, line.c_str());
			//đọc tên nhân viên
			std::getline(fin, line);
			strcpy(hd.TenNV, line.c_str());
			addTailHoaDon(l, hd);
		}
	}
	fin.close();//sau do dong file lai
}
// đọc danh sách chi tiết hóa đơn từ file
void LoadCTHoaDonTuFile(ListCTHoaDon& l)
{
	ifstream fin("DanhSachChiTietHoaDon.txt");// mở file
	if (fin.is_open())//kiểm tra mở file được hay không
	{
		int n = 0;
		fin >> n;
		string line;
		stringstream ss;
		std::getline(fin, line);//đọc file theo từng dòng
		for (int i = 0; i < n; i++)
		{// đọc mã hóa đơn
			std::getline(fin, line);
			CTHoaDon cthd;
			strcpy(cthd.Mahd, line.c_str());
			//đọc mã trà sữa
			std::getline(fin, line);
			strcpy(cthd.MaTS, line.c_str());
			//đọc số lượng
			std::getline(fin, line);
			ss << line;//Dung ham nay do chuyen doi tu kieu chuoi sang kieu so nguyen
			ss >> cthd.SoLuong;
			ss.clear();
			// đọc giá 
			std::getline(fin, line);
			ss << line;
			ss >> cthd.Gia;
			ss.clear();
			// thêm chi tiết hóa đơn vào danh sách
			addTailCTHoaDon(l, cthd);
		}
	}
	fin.close();//đóng lại file khi đọc xong
}
//đọc dữ liệu từ file
void LoadDataTuFile(ListTraSua& l, ListLoaiTraSua& loai, ListHoaDon& listhoadon, ListCTHoaDon& listchitiethoadon)
{
	LoadTraSuaTuFile(l);
	LoadLoaiTraSuaTuFile(loai);
	LoadHoaDonTuFile(listhoadon);
	LoadCTHoaDonTuFile(listchitiethoadon);
}
//đọc dữ liệu từ file
void GhiDataVaoFile(ListTraSua l, ListLoaiTraSua loai, ListHoaDon listhoadon, ListCTHoaDon listchitiethoadon)
{
	GhiTraSuaVaoFile(l);
	GhiLoaiTraSuaVaoFile(loai);
	GhiHoaDonVaoFile(listhoadon);
	GhiChiTietHoaDonVaoFile(listchitiethoadon);
}
// chức năng menu
int Menu()
{
	int select;
	cout << "                  XIN CHAO MUNG DEN VOI CUA HANG TRA SUA                      \n";
	cout << "\n======================CHUONG TRINH QUAN LY TRA SUA======================\n";
	cout << "1: Quan ly tra sua\n";
	cout << "2: Quan ly loai tra sua\n";
	cout << "3: Quan ly ban hang\n";
	cout << "0: Thoat\n";
	cout << "Ban chon so :";
	cin >> select;
	return select;
}
//khai báo về các chức năng chính của chương trình
//khai báo danh sách trà sữa,loại trà sữa,hóa đơn, chi tiết hóa đơn dưới dạng danh sách liên kết
void menuQLTS(ListTraSua& listrasua, ListLoaiTraSua& listloaitrasua) {
	int choice;
	do {
		cout << "\n======================QUAN LY TRA SUA======================\n";
		cout << "1: Nhap danh sach tra sua\n";
		cout << "2: Xuat danh sach tra sua\n";
		cout << "3: Xoa tra sua\n";
		cout << "4: Them tra sua\n";
		cout << "5: Tim kiem tra sua theo ten\n";
		cout << "6: Cap nhat tra sua\n";
		cout << "0: Thoat ra man hinh menu\n";
		cout << "Ban chon so :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			NhapDanhSachTraSua(listrasua, listloaitrasua);
			break;
		case 2:
			XuatDanhSachTraSua(listrasua);
			break;
		case 3:
			XoaTraSua(listrasua);
			break;
		case 4:
			TraSua trasua;
			cout << "Nhap thong tin tra sua " << endl;
			Nhap1TraSua(listrasua, listloaitrasua, trasua);
			addTail(listrasua, trasua);
			break;
		case 5:
			TimKiemTraSuaTheoTen(listrasua);
			break;
		case 6:
			Update1TraSua(listrasua, listloaitrasua);
			break;
		case 0:
			break;
		default:
			cout << "\nKhong co chuc nang nay!";
			cout << "\nHay chon chuc nang trong hop menu.";
			break;
		}
	} while (choice != 0);
}
//Menu quản lí loại trà sữa
void menuQLLTS(ListLoaiTraSua& listloaitrasua, ListTraSua& listtrasua) {
	int choice;
	do {
		cout << "\n======================QUAN LY LOAI TRA SUA======================\n";
		cout << "1: Nhap danh sach loai tra sua\n";
		cout << "2: Xuat danh sach loai tra sua\n";
		cout << "3: Xoa loai tra sua\n";
		cout << "4: Them loai tra sua\n";
		cout << "5: Tim kiem loai tra sua theo ten\n";
		cout << "6: Cap nhat loai tra sua\n";
		cout << "0: Thoat ra man hinh menu \n";
		cout << "Ban chon so :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			NhapDanhSachLoaiTraSua(listloaitrasua);
			break;
		case 2:
			XuatDanhSachLoaiTraSua(listloaitrasua);
			break;
		case 3:
			XoaLoaiTraSua(listloaitrasua, listtrasua);
			break;
		case 4:
			LoaiTraSua trasua;
			cout << "Nhap thong tin tra sua " << endl;
			Nhap1LoaiTraSua(listloaitrasua, trasua);
			addTailLoaiTraSua(listloaitrasua, trasua);
			break;
		case 5:
			TimKiemLoaiTraSuaTheoTen(listloaitrasua);
			break;
		case 6:
			Update1LoaiTraSua(listloaitrasua);
			break;
		case 0:
			break;
		default:
			cout << "\nKhong co chuc nang nay!";
			cout << "\nHay chon chuc nang trong hop menu.";
			break;
		}
	} while (choice != 0);
}

//Menu quản lí bán hàng
void menuQLBH(ListTraSua listrasua, ListHoaDon listhoadon, ListCTHoaDon listchitiethoadon) {
	int choice;
	do {
		cout << "\n======================QUAN LY BAN HANG======================\n";
		cout << "1: Ban va xuat hoa don\n";
		cout << "2: Thong ke hoa don theo ma hoa don\n";
		cout << "3: Thong ke doanh thu theo ngay\n";
		cout << "4: Thong ke doanh thu theo thang\n";
		cout << "0: Thoat ra man hinh menu \n";
		cout << "Ban chon so :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			BanTraSua(listrasua, listhoadon, listchitiethoadon);
			break;
		case 2:
			TimHoaDonTheoMa(listhoadon, listchitiethoadon, listrasua);
			break;
		case 3:
			ThongKeDoanhThuTheoNgay(listhoadon, listchitiethoadon, listrasua);
			break;
		case 4:
			ThongKeDoanhThuTheoThang(listhoadon, listchitiethoadon, listrasua);
			break;
		case 0:
			break;
		default:
			cout << "\nKhong co chuc nang nay!";
			cout << "\nHay chon chuc nang trong hop menu.";
			break;
		}
	} while (choice != 0);
}

int main()
{
	int select;
	ListTraSua listrasua;
	ListLoaiTraSua listloaitrasua;
	ListHoaDon listhoadon;
	ListCTHoaDon listchitiethoadon;
	InitListLoaiTraSua(listloaitrasua);
	InitListTraSua(listrasua);
	InitListHoaDon(listhoadon);
	InitListCTHoaDon(listchitiethoadon);
	LoadDataTuFile(listrasua, listloaitrasua, listhoadon, listchitiethoadon);
	do
	{
		select = Menu();
		switch (select)
		{
		case 0:
			GhiDataVaoFile(listrasua, listloaitrasua, listhoadon, listchitiethoadon);
			cout << "\nBan da chon thoat khoi chuong trinh";
			break;
		case 1:
			menuQLTS(listrasua, listloaitrasua);
			break;
		case 2:
			menuQLLTS(listloaitrasua,listrasua);
			break;
		case 3:
			menuQLBH(listrasua, listhoadon, listchitiethoadon);
			break;
		default:
			cout << "Nhap sai....\n";
			break;
		}
	} while (select != 0);
	return 0;
}
