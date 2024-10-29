#include <iostream>
#include <string>
using namespace std;

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct HangHoa {
    int maHH;
    string tenHH;
    Ngay ngayXuat;
    float giaXuat; 
};

void nhapHangHoa(HangHoa ds[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap ma hang hoa: ";
        cin >> ds[i].maHH;
        cin.ignore();  
        cout << "Nhap ten hang hoa: ";
        getline(cin, ds[i].tenHH);
        cout << "Nhap ngay xuat (ngay thang nam): ";
        cin >> ds[i].ngayXuat.ngay >> ds[i].ngayXuat.thang >> ds[i].ngayXuat.nam;
        cout << "Nhap gia xuat (trieu dong): ";
        cin >> ds[i].giaXuat;
        cin.ignore(); 
        cout << "------------------------------" << endl;
    }
}

void xuatHangHoa(HangHoa ds[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Ma hang hoa: " << ds[i].maHH << endl;
        cout << "Ten hang hoa: " << ds[i].tenHH << endl;
        cout << "Ngay xuat: " << ds[i].ngayXuat.ngay << "/" 
             << ds[i].ngayXuat.thang << "/" << ds[i].ngayXuat.nam << endl;
        cout << "Gia xuat: " << ds[i].giaXuat << " trieu dong" << endl;
        cout << "------------------------------" << endl;
    }
}

void sapXepTangDan(HangHoa ds[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ds[i].giaXuat > ds[j].giaXuat) {
                HangHoa p = ds[i];
                ds[i] = ds[j];
                ds[j] = p;
            }
        }
    }
}
void timHangHoaTheoGia(HangHoa ds[], int n, float x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;   
        if (ds[mid].giaXuat == x) {
            cout << "Hang hoa co gia xuat = " << x << ":" << endl;
            cout << "Ma hang hoa: " << ds[mid].maHH << endl;
            cout << "Ten hang hoa: " << ds[mid].tenHH << endl;
            cout << "Ngay xuat: " << ds[mid].ngayXuat.ngay << "/" 
                 << ds[mid].ngayXuat.thang << "/" << ds[mid].ngayXuat.nam << endl;
            cout << "Gia xuat: " << ds[mid].giaXuat << " trieu dong" << endl;
            return;
        }
        if (ds[mid].giaXuat < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Khong tim thay hang hoa co gia xuat = " << x << endl;
}

int main() {
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    cin.ignore();  
    HangHoa* ds = new HangHoa[n];
    nhapHangHoa(ds, n);
    cout << "Danh sach hang hoa vua nhap:" << endl;
    xuatHangHoa(ds, n);
    sapXepTangDan(ds, n);
    cout << "Danh sach hang hoa sau khi sap xep:" << endl;
    xuatHangHoa(ds, n);
    float x;
    cout << "Nhap gia xuat de tim (trieu dong): ";
    cin >> x;
    timHangHoaTheoGia(ds, n, x);
    delete[] ds;
    return 0;
}
