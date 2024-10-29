#include <iostream>
#include <string>
using namespace std;

struct KhachHang {
    int maKhachHang;
    string tenKhachHang;
    string soDienThoai;
    double tongTienThanhToan;
};

void nhapKhachHang(KhachHang dsKhachHang[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho khach hang thu " << (i + 1) << ":\n";
        cout << "Ma khach hang: ";
        cin >> dsKhachHang[i].maKhachHang;
        cin.ignore(); // Bo qua ky tu xuong dong
        cout << "Ten khach hang: ";
        getline(cin, dsKhachHang[i].tenKhachHang);
        cout << "So dien thoai: ";
        getline(cin, dsKhachHang[i].soDienThoai);
        cout << "Tong tien thanh toan: ";
        cin >> dsKhachHang[i].tongTienThanhToan;
    }
}

void xuatKhachHang(KhachHang dsKhachHang[], int n) {
    cout << "Danh sach khach hang:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma KH: " << dsKhachHang[i].maKhachHang 
             << ", Ten KH: " << dsKhachHang[i].tenKhachHang 
             << ", SDT: " << dsKhachHang[i].soDienThoai 
             << ", Tong tien thanh toan: " << dsKhachHang[i].tongTienThanhToan << endl;
    }
}

void sapXepKhachHang(KhachHang dsKhachHang[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang x = dsKhachHang[i];
        int pos = i - 1;
        while (pos >= 0 && dsKhachHang[pos].tongTienThanhToan > x.tongTienThanhToan) {
            dsKhachHang[pos + 1] = dsKhachHang[pos];
            pos--;
        }
        dsKhachHang[pos + 1] = x; // Chen khach hang vao vi tri dung
    }
}

void timKiemKhachHang(KhachHang dsKhachHang[], int n, double X) {
    int left = 0, right = n - 1;
    bool found = false;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dsKhachHang[mid].tongTienThanhToan == X) {
            cout << "Khach hang co tong tien thanh toan bang " << X << ":\n";
            cout << "Ma KH: " << dsKhachHang[mid].maKhachHang 
                 << ", Ten KH: " << dsKhachHang[mid].tenKhachHang 
                 << ", SDT: " << dsKhachHang[mid].soDienThoai 
                 << ", Tong tien thanh toan: " << dsKhachHang[mid].tongTienThanhToan << endl;
            found = true;
            int i = mid - 1;
            while (i >= 0 && dsKhachHang[i].tongTienThanhToan == X) {
                cout << "Ma KH: " << dsKhachHang[i].maKhachHang 
                     << ", Ten KH: " << dsKhachHang[i].tenKhachHang 
                     << ", SDT: " << dsKhachHang[i].soDienThoai 
                     << ", Tong tien thanh toan: " << dsKhachHang[i].tongTienThanhToan << endl;
                i--;
            }
            int j = mid + 1;
            while (j < n && dsKhachHang[j].tongTienThanhToan == X) {
                cout << "Ma KH: " << dsKhachHang[j].maKhachHang 
                     << ", Ten KH: " << dsKhachHang[j].tenKhachHang 
                     << ", SDT: " << dsKhachHang[j].soDienThoai 
                     << ", Tong tien thanh toan: " << dsKhachHang[j].tongTienThanhToan << endl;
                j++;
            }
            break;
        } else if (dsKhachHang[mid].tongTienThanhToan < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "Khong co khach hang nao co tong tien thanh toan bang " << X << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;
    KhachHang dsKhachHang[n];
    nhapKhachHang(dsKhachHang, n);
    cout << "\nDanh sach khach hang vua nhap:\n";
    xuatKhachHang(dsKhachHang, n);
    sapXepKhachHang(dsKhachHang, n);
    cout << "\nDanh sach khach hang sau khi sap xep tang dan theo tong tien thanh toan:\n";
    xuatKhachHang(dsKhachHang, n);
    double X;
    cout << "\nNhap tong tien thanh toan can tim: ";
    cin >> X;
    timKiemKhachHang(dsKhachHang, n, X);
    return 0;
}

