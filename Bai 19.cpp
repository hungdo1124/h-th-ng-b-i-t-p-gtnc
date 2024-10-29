#include <iostream>
#include <string>
using namespace std;

struct DuAn {
    int maDuAn;
    string tenDuAn;
    double tongKinhPhi;
};

void nhapDuAn(DuAn dsDuAn[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho du an thu " << (i + 1) << ":\n";
        cout << "Ma du an: ";
        cin >> dsDuAn[i].maDuAn;
        cin.ignore(); // Bo qua ky tu xuong dong
        cout << "Ten du an: ";
        getline(cin, dsDuAn[i].tenDuAn);
        cout << "Tong kinh phi (ty dong): ";
        cin >> dsDuAn[i].tongKinhPhi;
    }
}

void xuatDuAn(DuAn dsDuAn[], int n) {
    cout << "Danh sach du an:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma DA: " << dsDuAn[i].maDuAn 
             << ", Ten DA: " << dsDuAn[i].tenDuAn 
             << ", Tong kinh phi: " << dsDuAn[i].tongKinhPhi << " ty dong\n";
    }
}

void sapXepDuAn(DuAn dsDuAn[], int n) {
    for (int i = 1; i < n; i++) {
        DuAn x = dsDuAn[i];
        int pos = i - 1;
        while (pos >= 0 && dsDuAn[pos].tongKinhPhi > x.tongKinhPhi) {
            dsDuAn[pos + 1] = dsDuAn[pos];
            pos--;
        }
        dsDuAn[pos + 1] = x; // Chen du an vao vi tri dung
    }
}

void timKiemDuAn(DuAn dsDuAn[], int n, double X) {
    int left = 0, right = n - 1;
    bool found = false;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dsDuAn[mid].tongKinhPhi == X) {
            cout << "Du an co tong kinh phi bang " << X << " ty dong:\n";
            cout << "Ma DA: " << dsDuAn[mid].maDuAn 
                 << ", Ten DA: " << dsDuAn[mid].tenDuAn 
                 << ", Tong kinh phi: " << dsDuAn[mid].tongKinhPhi << " ty dong\n";
            found = true;
            int i = mid - 1;
            while (i >= 0 && dsDuAn[i].tongKinhPhi == X) {
                cout << "Ma DA: " << dsDuAn[i].maDuAn 
                     << ", Ten DA: " << dsDuAn[i].tenDuAn 
                     << ", Tong kinh phi: " << dsDuAn[i].tongKinhPhi << " ty dong\n";
                i--;
            }
            int j = mid + 1;
            while (j < n && dsDuAn[j].tongKinhPhi == X) {
                cout << "Ma DA: " << dsDuAn[j].maDuAn 
                     << ", Ten DA: " << dsDuAn[j].tenDuAn 
                     << ", Tong kinh phi: " << dsDuAn[j].tongKinhPhi << " ty dong\n";
                j++;
            }
            break;
        } else if (dsDuAn[mid].tongKinhPhi < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Khong co du an nao co tong kinh phi bang " << X << " ty dong\n";
    }
}

int main() {
    int n;
    cout << "Nhap so luong du an: ";
    cin >> n;
    DuAn dsDuAn[n];
    nhapDuAn(dsDuAn, n);
    cout << "\nDanh sach du an vua nhap:\n";
    xuatDuAn(dsDuAn, n);
    sapXepDuAn(dsDuAn, n);
    cout << "\nDanh sach du an sau khi sap xep tang dan theo tong kinh phi:\n";
    xuatDuAn(dsDuAn, n);
    double X;
    cout << "\nNhap tong kinh phi can tim (ty dong): ";
    cin >> X;
    timKiemDuAn(dsDuAn, n, X);
    return 0;
}

