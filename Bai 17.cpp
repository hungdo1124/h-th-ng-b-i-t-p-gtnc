#include <iostream>
#include <string>
using namespace std;

struct TaiLieu {
    int maTaiLieu;
    string tenTaiLieu;
    int namXuatBan;
    double giaBan;
};

void nhapTaiLieu(TaiLieu dsTaiLieu[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho tai lieu thu " << (i + 1) << ":\n";
        cout << "Ma tai lieu: ";
        cin >> dsTaiLieu[i].maTaiLieu;
        cin.ignore();
        cout << "Ten tai lieu: ";
        getline(cin, dsTaiLieu[i].tenTaiLieu);
        cout << "Nam xuat ban: ";
        cin >> dsTaiLieu[i].namXuatBan;
        cout << "Gia ban: ";
        cin >> dsTaiLieu[i].giaBan;
    }
}

void xuatTaiLieu(TaiLieu dsTaiLieu[], int n) {
    cout << "Danh sach tai lieu:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma TL: " << dsTaiLieu[i].maTaiLieu 
             << ", Ten TL: " << dsTaiLieu[i].tenTaiLieu 
             << ", Nam XB: " << dsTaiLieu[i].namXuatBan 
             << ", Gia ban: " << dsTaiLieu[i].giaBan << " trieu dong\n";
    }
}

void sapXepTaiLieu(TaiLieu dsTaiLieu[], int n) {
    for (int i = 1; i < n; i++) {
        TaiLieu x = dsTaiLieu[i];
        int pos = i - 1;
        while (pos >= 0 && dsTaiLieu[pos].giaBan > x.giaBan) {
            dsTaiLieu[pos + 1] = dsTaiLieu[pos];
            pos--;
        }
        dsTaiLieu[pos + 1] = x; // Chen tai lieu vao vi tri dung
    }
}

void timKiemTaiLieu(TaiLieu dsTaiLieu[], int n, double X) {
    int left = 0, right = n - 1;
    bool found = false;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dsTaiLieu[mid].giaBan == X) {
            cout << "Tai lieu co gia ban bang " << X << " trieu dong:\n";
            cout << "Ma TL: " << dsTaiLieu[mid].maTaiLieu 
                 << ", Ten TL: " << dsTaiLieu[mid].tenTaiLieu 
                 << ", Nam XB: " << dsTaiLieu[mid].namXuatBan 
                 << ", Gia ban: " << dsTaiLieu[mid].giaBan << " trieu dong\n";
            found = true;
            int i = mid - 1;
            while (i >= 0 && dsTaiLieu[i].giaBan == X) {
                cout << "Ma TL: " << dsTaiLieu[i].maTaiLieu 
                     << ", Ten TL: " << dsTaiLieu[i].tenTaiLieu 
                     << ", Nam XB: " << dsTaiLieu[i].namXuatBan 
                     << ", Gia ban: " << dsTaiLieu[i].giaBan << " trieu dong\n";
                i--;
            }
            int j = mid + 1;
            while (j < n && dsTaiLieu[j].giaBan == X) {
                cout << "Ma TL: " << dsTaiLieu[j].maTaiLieu 
                     << ", Ten TL: " << dsTaiLieu[j].tenTaiLieu 
                     << ", Nam XB: " << dsTaiLieu[j].namXuatBan 
                     << ", Gia ban: " << dsTaiLieu[j].giaBan << " trieu dong\n";
                j++;
            }
            break;
        } else if (dsTaiLieu[mid].giaBan < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Khong co tai lieu nao co gia ban bang " << X << " trieu dong\n";
    }
}

int main() {
    int n;
    cout << "Nhap so luong tai lieu: ";
    cin >> n;
    TaiLieu dsTaiLieu[n];
    nhapTaiLieu(dsTaiLieu, n);
    cout << "\nDanh sach tai lieu vua nhap:\n";
    xuatTaiLieu(dsTaiLieu, n);
    sapXepTaiLieu(dsTaiLieu, n);
    cout << "\nDanh sach tai lieu sau khi sap xep tang dan theo gia ban:\n";
    xuatTaiLieu(dsTaiLieu, n);
    double X;
    cout << "\nNhap gia ban can tim (trieu dong): ";
    cin >> X;
    timKiemTaiLieu(dsTaiLieu, n, X);
    return 0;
}

