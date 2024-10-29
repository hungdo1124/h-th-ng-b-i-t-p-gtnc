#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float tongKet;
};

void hoanVi(SinhVien &a, SinhVien &b) {
    SinhVien p = a;
    a = b;
    b = p;
}

void nhapSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap ma sinh vien: ";
        cin >> ds[i].maSV;
        cin.ignore(); 
        cout << "Nhap ten sinh vien: ";
        getline(cin, ds[i].tenSV);
        cout << "Nhap lop: ";
        getline(cin, ds[i].lop);
        cout << "Nhap tong ket: ";
        cin >> ds[i].tongKet;
        cin.ignore(); 
        cout << "------------------------------" << endl;
    }
}

void xuatSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Ma sinh vien: " << ds[i].maSV << endl;
        cout << "Ten sinh vien: " << ds[i].tenSV << endl;
        cout << "Lop: " << ds[i].lop << endl;
        cout << "Tong ket: " << ds[i].tongKet << endl;
        cout << "------------------------------" << endl;
    }
}

void sapXepTangDan(SinhVien ds[], int n) {
    int i, j, min;
    
    for (i = 0; i < n - 1; ++i) {
        min = i; 
        for (j = i + 1; j < n; ++j) {
            if (ds[j].tongKet < ds[min].tongKet) {
                min = j; 
            }
        }
        if (min != i) {
            hoanVi(ds[i], ds[min]);
        }
    }
}

void timSinhVienTheoTongKet(SinhVien ds[], int n, float x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;   
        if (ds[mid].tongKet == x) {
            cout << "Sinh vien co tong ket = " << x << ":" << endl;
            cout << "Ma sinh vien: " << ds[mid].maSV << endl;
            cout << "Ten sinh vien: " << ds[mid].tenSV << endl;
            cout << "Lop: " << ds[mid].lop << endl;
            cout << "Tong ket: " << ds[mid].tongKet << endl;
            return;
        }
        if (ds[mid].tongKet < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Khong tim thay sinh vien co tong ket = " << x << endl;
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();  
    SinhVien* ds = new SinhVien[n];
    nhapSinhVien(ds, n);
    cout << "Danh sach sinh vien vua nhap:" << endl;
    xuatSinhVien(ds, n);
    sapXepTangDan(ds, n);
    cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    xuatSinhVien(ds, n);
    float x;
    cout << "Nhap tong ket de tim: ";
    cin >> x;
    timSinhVienTheoTongKet(ds, n, x);
    delete[] ds;
    return 0;
}
