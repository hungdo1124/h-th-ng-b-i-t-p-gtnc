#include <iostream>
#include <string>
using namespace std;

struct VanDongVien {
    int maVDV;
    string tenVDV;
    int tuoi;
    float luong;
};

void nhapVDV(VanDongVien dsVDV[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho van dong vien thu " << (i + 1) << ":\n";
        cout << "Ma VDV: ";
        cin >> dsVDV[i].maVDV;
        cin.ignore();
        cout << "Ten VDV: ";
        getline(cin, dsVDV[i].tenVDV);
        cout << "Tuoi: ";
        cin >> dsVDV[i].tuoi;
        cout << "Luong (trieu dong): ";
        cin >> dsVDV[i].luong;
    }
}

void xuatVDV(VanDongVien dsVDV[], int n) {
    cout << "Danh sach van dong vien:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma VDV: " << dsVDV[i].maVDV 
             << ", Ten VDV: " << dsVDV[i].tenVDV 
             << ", Tuoi: " << dsVDV[i].tuoi 
             << ", Luong: " << dsVDV[i].luong << " trieu dong\n";
    }
}

void sapXepVDV(VanDongVien dsVDV[], int n) {
    for (int i = 1; i < n; i++) {
        VanDongVien x = dsVDV[i];
        int pos = i - 1;
        while (pos >= 0 && dsVDV[pos].luong > x.luong) {
            dsVDV[pos + 1] = dsVDV[pos];
            pos--;
        }
        dsVDV[pos + 1] = x; // Chen van dong vien vao vi tri dung
    }
}

void timKiemVDV(VanDongVien dsVDV[], int n, float X) {
    int left = 0, right = n - 1;
    bool found = false;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dsVDV[mid].luong == X) {
            cout << "Van dong vien co luong bang " << X << " trieu dong:\n";
            cout << "Ma VDV: " << dsVDV[mid].maVDV 
                 << ", Ten VDV: " << dsVDV[mid].tenVDV 
                 << ", Tuoi: " << dsVDV[mid].tuoi 
                 << ", Luong: " << dsVDV[mid].luong << " trieu dong\n";
            found = true;
            int i = mid - 1;
            while (i >= 0 && dsVDV[i].luong == X) {
                cout << "Ma VDV: " << dsVDV[i].maVDV 
                     << ", Ten VDV: " << dsVDV[i].tenVDV 
                     << ", Tuoi: " << dsVDV[i].tuoi 
                     << ", Luong: " << dsVDV[i].luong << " trieu dong\n";
                i--;
            }
            int j = mid + 1;
            while (j < n && dsVDV[j].luong == X) {
                cout << "Ma VDV: " << dsVDV[j].maVDV 
                     << ", Ten VDV: " << dsVDV[j].tenVDV 
                     << ", Tuoi: " << dsVDV[j].tuoi 
                     << ", Luong: " << dsVDV[j].luong << " trieu dong\n";
                j++;
            }
            break;
        } else if (dsVDV[mid].luong < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "Khong co van dong vien nao co luong bang " << X << " trieu dong\n";
    }
}

int main() {
    int n;
    cout << "Nhap so luong van dong vien: ";
    cin >> n;
    VanDongVien dsVDV[n];
    nhapVDV(dsVDV, n);
    cout << "\nDanh sach van dong vien vua nhap:\n";
    xuatVDV(dsVDV, n);
    sapXepVDV(dsVDV, n);
    cout << "\nDanh sach van dong vien sau khi sap xep tang dan theo luong:\n";
    xuatVDV(dsVDV, n);
    float X;
    cout << "\nNhap luong can tim (trieu dong): ";
    cin >> X;
    timKiemVDV(dsVDV, n, X);
    return 0;
}

