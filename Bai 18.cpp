#include <iostream>
#include <string>
using namespace std;

struct VeMayBay {
    int maVe;
    string khoiHanh;
    string den;
    double giaVe;
};

void nhapVeMayBay(VeMayBay dsVe[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho ve may bay thu " << (i + 1) << ":\n";
        cout << "Ma ve: ";
        cin >> dsVe[i].maVe;
        cin.ignore();
        cout << "Noi khoi hanh: ";
        getline(cin, dsVe[i].khoiHanh);
        cout << "Noi den: ";
        getline(cin, dsVe[i].den);
        cout << "Gia ve: ";
        cin >> dsVe[i].giaVe;
    }
}

void xuatVeMayBay(VeMayBay dsVe[], int n) {
    cout << "Danh sach ve may bay:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma ve: " << dsVe[i].maVe 
             << ", Khoi hanh: " << dsVe[i].khoiHanh 
             << ", Den: " << dsVe[i].den 
             << ", Gia ve: " << dsVe[i].giaVe << " trieu dong\n";
    }
}

void sapXepVeMayBay(VeMayBay dsVe[], int n) {
    for (int i = 1; i < n; i++) {
        VeMayBay x = dsVe[i];
        int pos = i - 1;
        while (pos >= 0 && dsVe[pos].giaVe > x.giaVe) {
            dsVe[pos + 1] = dsVe[pos];
            pos--;
        }
        dsVe[pos + 1] = x; // Chen ve vao vi tri dung
    }
}

void timKiemVeMayBay(VeMayBay dsVe[], int n, double X) {
    int left = 0, right = n - 1;
    bool found = false;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dsVe[mid].giaVe == X) {
            cout << "Ve may bay co gia ve bang " << X << " trieu dong:\n";
            cout << "Ma ve: " << dsVe[mid].maVe 
                 << ", Khoi hanh: " << dsVe[mid].khoiHanh 
                 << ", Den: " << dsVe[mid].den 
                 << ", Gia ve: " << dsVe[mid].giaVe << " trieu dong\n";
            found = true;
            int i = mid - 1;
            while (i >= 0 && dsVe[i].giaVe == X) {
                cout << "Ma ve: " << dsVe[i].maVe 
                     << ", Khoi hanh: " << dsVe[i].khoiHanh 
                     << ", Den: " << dsVe[i].den 
                     << ", Gia ve: " << dsVe[i].giaVe << " trieu dong\n";
                i--;
            }
            int j = mid + 1;
            while (j < n && dsVe[j].giaVe == X) {
                cout << "Ma ve: " << dsVe[j].maVe 
                     << ", Khoi hanh: " << dsVe[j].khoiHanh 
                     << ", Den: " << dsVe[j].den 
                     << ", Gia ve: " << dsVe[j].giaVe << " trieu dong\n";
                j++;
            }
            break;
        } else if (dsVe[mid].giaVe < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Khong co ve may bay nao co gia ve bang " << X << " trieu dong\n";
    }
}

int main() {
    int n;
    cout << "Nhap so luong ve may bay: ";
    cin >> n;
    VeMayBay dsVe[n];
    nhapVeMayBay(dsVe, n);
    cout << "\nDanh sach ve may bay vua nhap:\n";
    xuatVeMayBay(dsVe, n);
    sapXepVeMayBay(dsVe, n);
    cout << "\nDanh sach ve may bay sau khi sap xep tang dan theo gia ve:\n";
    xuatVeMayBay(dsVe, n);
    double X;
    cout << "\nNhap gia ve can tim (trieu dong): ";
    cin >> X;
    timKiemVeMayBay(dsVe, n, X);
    return 0;
}

