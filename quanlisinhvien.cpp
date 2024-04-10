#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <cmath>
using namespace std;
int dem = 0;
struct SinhVien
{
    int mssv;
    char hoten[50];
    char gioitinh[10];
    char lop[30];
    char nganhhoc[30];
    char diachi[50];
    float diem1, diem2, diem3, diemm;

    void nhap()
    {
        cout << "Nhap MSSV: ";
        cin >> mssv;
        cout << "Nhap ho ten: ";
        fflush(stdin);
        gets(hoten);
        cout << "Nhap gioi tinh: ";
        cin >> gioitinh;
        cout << "Nhap lop: ";
        cin >> lop;
        cout << "Nhap nganh hoc: ";
        cin >> nganhhoc;
        cout << "Nhap dia chi: ";
        cin >> diachi;
        do
        {
            cout << "Nhap diem 1: ";
            cin >> diem1;
            cout << "Nhap diem 2: ";
            cin >> diem2;
            cout << "Nhap diem 3: ";
            cin >> diem3;
            if (diem1 < 0 || diem2 < 0 || diem3 < 0 || diem1 > 10 || diem2 > 10 || diem3 > 10)
            {
                cout << "Diem nhap khong hop le\n";
            }
        } while (diem1 < 0 || diem2 < 0 || diem3 < 0 || diem1 > 10 || diem2 > 10 || diem3 > 10);
    }

    float diemtb()
    {
        float tong_diem = diem1 + diem2 + diem3;
        return round((tong_diem / 3) * 100) / 100;
    }
    string hocluc()
    {
        string hocluc;
        if (diemtb() >= 9)
            hocluc = "Xuat sac";
        else if (diemtb() >= 8)
            hocluc = "Gioi";
        else if (diemtb() >= 6.5)
            hocluc = "Kha";
        else if (diemtb() >= 5)
            hocluc = "Trung binh";
        else
            hocluc = "Yeu";
        return hocluc;
    }
    void xuat()
    {
        cout << setw(2) << ++dem << setw(8) << mssv << setw(16) << hoten << setw(8) << gioitinh << setw(14) << lop << setw(9) << nganhhoc << setw(10) << diachi << setw(10) << diem1;
        cout << setw(10) << diem2 << setw(9) << diem3 << setw(11) << diemtb() << setw(10) << hocluc() << endl;
    }
};
typedef SinhVien SV;
void NhapSl(int &n)
{

    do
    {
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "So luong sinh vien phai lon hon 0" << endl;
        }
    } while (n <= 0);
}
void NhapDSSV(SV *sv, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        do
        {
            res = 0;
            cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
            sv[i].nhap();
            for (int j = 0; j < i; j++)
            {
                if (sv[i].mssv == sv[j].mssv)
                {
                    cout << "MSSV da ton tai" << endl;
                    break;
                }
            }
        } while (res != 0);
    }
}
void title()
{
    cout << setw(2) << "STT" << setw(8) << "MSV" << setw(10) << "ho ten" << setw(16) << "gioi tinh" << setw(8) << "lop" << setw(14) << "nganh hoc" << setw(10) << "dia chi" << setw(10) << "diem 1";
    cout << setw(10) << "Diem 2" << setw(10) << "Diem 3" << setw(10) << "diemtb" << setw(10) << "Hoc luc" << endl;
}
void XuatDSSV(SV *sv, int n)
{
    title();
    dem = 0;
    for (int i = 0; i < n; i++)
    {
        sv[i].xuat();
    }
}
void themtt(SV *sv, int &n)
{
    n++;
    int res = 0;
    dem = 0;
    do
    {
        res = 0;
        cout << "Nhap thong tin sinh vien can them" << endl;
        sv[n - 1].nhap();
        for (int i = 0; i < n - 1; i++)
        {
            if (sv[i].mssv == sv[n - 1].mssv)
            {
                cout << "MSSV da ton tai" << endl;
                res++;
            }
        }
    } while (res != 0);
    cout << "Them thanh cong" << endl;
}
void Xoatt(SV *sv, int &n)
{
    int soct;
    dem = 0;
    int res = 0;
    cout << "Nhap mssv cua sinh vien muon xoa: ";
    cin >> soct;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].mssv == soct)
        {
            res++;
            for (int j = i; j < n; j++)
            {
                sv[j] = sv[j + 1];
            }
        }
    }
    if (res == 0)
    {
        cout << "Khong tim thay sinh vien can xoa" << endl;
    }
    else
        n--;
    cout << "Xoa thanh cong" << endl;
}
void chinhsuatt(SV *sv, int n)
{
    int soct;
    dem = 0;
    int res = 0;
    cout << "Nhap mssv cua sinh vien muon chinh sua: ";
    cin >> soct;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].mssv == soct)
        {
            res++;
            sv[i].nhap();
        }
    }
    if (res == 0)
    {
        cout << "Khong tim thay sinh vien can chinh sua" << endl;
    }
}
float max(SV *sv, int n)
{
    float max = sv[0].diemtb();
    for (int i = 1; i < n; i++)
    {
        if (sv[i].diemtb() > max)
            max = sv[i].diemtb();
    }
    return max;
}
float min(SV *sv, int n)
{
    float min = sv[0].diemtb();
    for (int i = 1; i < n; i++)
    {
        if (sv[i].diemtb() < min)
            min = sv[i].diemtb();
    }
    return min;
}
void printmax(SV *sv, int n)
{
    cout << "Sinh vien co diem tb cao nhat la: " << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        if (sv[i].diemtb() == max(sv, n))

            sv[i].xuat();
    }
}
void printmin(SV *sv, int n)
{
    cout << "Sinh vien co diem tb thap nhat la: " << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        if (sv[i].diemtb() == min(sv, n))
            sv[i].xuat();
    }
}
void timsvmsv(SV *sv, int n)
{
    int soct;
    int res = 0;
    cout << "Nhap mssv cua sinh vien muon tim bang mssv: ";
    cin >> soct;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].mssv == soct)
        {
            res++;
            title();
            sv[i].xuat();
        }
    }
    if (res == 0)
    {
        cout << "Khong tim thay sinh vien can tim" << endl;
    }
}
void timsvhoten(SV *sv, int n)
{
    char hoten[50];
    int res = 0;
    cout << "Nhap ho ten cua sinh vien muon tim bang ho ten: ";
    fflush(stdin);
    gets(hoten);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(sv[i].hoten, hoten) == 0)
        {
            res++;
            title();
            sv[i].xuat();
        }
    }
    if (res == 0)
    {
        cout << "Khong tim thay sinh vien can tim" << endl;
    }
}

void exportFile(int n, SinhVien *svList)
{
    dem = 0;
    system("cls");
    if (n == 0)
    {
        cout << "Khong co sv nao!";
        system("pause");
        return;
    }
    fstream outfile;
    outfile.open("ExportData.csv", ios::out);
    outfile << "STT,MSV,Ho va ten,Gioi tinh,lop,nganh hoc,dia chi,Diem 1,Diem 2,Diem 3,Diem tb,Xep loai" << endl;
    for (int i = 0; i < n; i++)
    {
        outfile << ++dem << "," << svList[i].mssv << "," << svList[i].hoten << "," << svList[i].gioitinh << "," << svList[i].lop << "," << svList[i].nganhhoc << "," << svList[i].diachi << "," << svList[i].diem1 << "," << svList[i].diem2 << "," << svList[i].diem3 << "," << svList[i].diemtb() << "," << svList[i].hocluc() << endl;
    }
    outfile.close();
    cout << "Xuat file csv thanh cong" << endl;
    system("pause");
}

void Menu()
{
    cout << "\t    CHAO MUNG DEN VOI CHUONG TRINH QUAN LI SINH VIEN";
    cout << "\n                                                                      ";
    cout << "\n********************************";
    cout << " MENU ";
    cout << "********************************";
    cout << "\n|                                                                    |";
    cout << "\n|\t1. Nhap danh sach sinh vien                                  |" << "\n";
    cout << "| \t2. Xuat danh sach sinh vien                                  |" << "\n";
    cout << "| \t3. Them thong tin 1 sinh vien                                |" << "\n";
    cout << "| \t4. Xoa thong tin 1 sinh vien                                 |" << "\n";
    cout << "| \t5. Chinh sua thong tin 1 sinh vien                           |" << "\n";
    cout << "| \t6. Tim sinh vien co diem trung binh cao nhat                 |" << "\n";
    cout << "| \t7. Tim sinh vien co diem trung binh thap nhat                |" << "\n";
    cout << "| \t8. Tim sinh vien theo mssv                                   |" << "\n";
    cout << "| \t9. Tim sinh vien theo hoten                                  |" << "\n";
    cout << "| \t10. Xuat du lieu sinh vien sang file csv                     |" << "\n";
    cout << "|                                                                    |" << "\n";
    cout << "**************************************";
    cout << "********************************";
}
int main()
{

    int n = 0;
    SV *sv;
    int choice;

    sv = new SV[100];
    char chonlai;
    // menu

    do
    {
        Menu();
        cout << "\n Nhap lua chon: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            NhapSl(n);
            NhapDSSV(sv, n);
            break;
        case 2:
            cout << "Danh sach sinh vien" << endl;
            XuatDSSV(sv, n);
            break;
        case 3:
            themtt(sv, n);

            break;
        case 4:
            Xoatt(sv, n);
            break;
        case 5:
            chinhsuatt(sv, n);
            break;
        case 6:
            printmax(sv, n);

            break;
        case 7:
            printmin(sv, n);
            break;
        case 8:
            timsvmsv(sv, n);
            break;
        case 9:
            timsvhoten(sv, n);
            break;
        case 10:
            exportFile(n, sv);
            break;
        default:

            break;
        }
        cout << "\n Ban co muon lua chon tiep khong(y/n):";
        cin >> chonlai;
    } while (chonlai == 'y');

    delete[] sv;
    return 0;
}