#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    int maNhanVien;
    string hoTen;
    string ngaySinh; 
    double luong;
};

void nhapNhanVien(NhanVien dsNhanVien[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho nhan vien thu " << (i + 1) << ":\n";
        cout << "Ma nhan vien: ";
        cin >> dsNhanVien[i].maNhanVien;
        cin.ignore(); // Bo qua ky tu xuong dong
        cout << "Ho ten: ";
        getline(cin, dsNhanVien[i].hoTen);
        cout << "Ngay sinh (dd/mm/yyyy): ";
        getline(cin, dsNhanVien[i].ngaySinh);
        cout << "Luong (trieu dong): ";
        cin >> dsNhanVien[i].luong;
    }
}

void xuatNhanVien(NhanVien dsNhanVien[], int n) {
    cout << "Danh sach nhan vien:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma NV: " << dsNhanVien[i].maNhanVien 
             << ", Ho ten: " << dsNhanVien[i].hoTen 
             << ", Ngay sinh: " << dsNhanVien[i].ngaySinh 
             << ", Luong: " << dsNhanVien[i].luong << " trieu dong\n";
    }
}

void sapXepNhanVien(NhanVien dsNhanVien[], int n) {
    for (int i = 1; i < n; i++) {
        NhanVien x = dsNhanVien[i];
        int pos = i - 1;
        while (pos >= 0 && dsNhanVien[pos].luong > x.luong) {
            dsNhanVien[pos + 1] = dsNhanVien[pos];
            pos--;
        }
        dsNhanVien[pos + 1] = x;
    }
}

void timKiemNhanVien(NhanVien dsNhanVien[], int n, double X) {
    int left = 0, right = n - 1;
    bool found = false;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dsNhanVien[mid].luong == X) {
            cout << "Nhan vien co luong bang " << X << " trieu dong:\n";
            cout << "Ma NV: " << dsNhanVien[mid].maNhanVien 
                 << ", Ho ten: " << dsNhanVien[mid].hoTen 
                 << ", Ngay sinh: " << dsNhanVien[mid].ngaySinh 
                 << ", Luong: " << dsNhanVien[mid].luong << " trieu dong\n";
            found = true;
            int i = mid - 1;
            while (i >= 0 && dsNhanVien[i].luong == X) {
                cout << "Ma NV: " << dsNhanVien[i].maNhanVien 
                     << ", Ho ten: " << dsNhanVien[i].hoTen 
                     << ", Ngay sinh: " << dsNhanVien[i].ngaySinh 
                     << ", Luong: " << dsNhanVien[i].luong << " trieu dong\n";
                i--;
            }
            int j = mid + 1;
            while (j < n && dsNhanVien[j].luong == X) {
                cout << "Ma NV: " << dsNhanVien[j].maNhanVien 
                     << ", Ho ten: " << dsNhanVien[j].hoTen 
                     << ", Ngay sinh: " << dsNhanVien[j].ngaySinh 
                     << ", Luong: " << dsNhanVien[j].luong << " trieu dong\n";
                j++;
            }
            break;
        } else if (dsNhanVien[mid].luong < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "Khong co nhan vien nao co luong bang " << X << " trieu dong\n";
    }
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    NhanVien dsNhanVien[n];
    nhapNhanVien(dsNhanVien, n);
    cout << "\nDanh sach nhan vien vua nhap:\n";
    xuatNhanVien(dsNhanVien, n);
    sapXepNhanVien(dsNhanVien, n);
    cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo luong:\n";
    xuatNhanVien(dsNhanVien, n);
    double X;
    cout << "\nNhap luong can tim (trieu dong): ";
    cin >> X;
    timKiemNhanVien(dsNhanVien, n, X);
    return 0;
}

