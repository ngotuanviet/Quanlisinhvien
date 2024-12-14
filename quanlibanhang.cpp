#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

struct HangHoa
{
    string tenHang;
    string nhaSanXuat;
    string diaChikho;
    int maHangHoa;
    int soLuong;
    float donGia;
    double tinhDonGiaTong() const
    {
        return static_cast<double>(soLuong) * donGia;
    }
};

HangHoa inputData()
{ // Hàm nhập thông tin dùng chung
    HangHoa temp;
    cout << "Nhap ma hang hoa: ";
    cin >> temp.maHangHoa;
    cout << "Nhap ten hang hoa: ";
    fflush(stdin);
    getline(cin, temp.tenHang);
    cout << "Nhap so luong: ";
    cin >> temp.soLuong;
    cout << "Nhap don gia: ";
    cin >> temp.donGia;
    cout << "Nhap nha san xuat: ";
    fflush(stdin);
    getline(cin, temp.nhaSanXuat);
    cout << "Nhap dia chi kho: ";
    fflush(stdin);
    getline(cin, temp.diaChikho); //
    return temp;
}
void title()
{

    cout << setw(3) << "MaHangHoa" << setw(15) << "TenHangHoa" << setw(13) << "Soluong" << setw(8) << "Dongia" << setw(14) << "Nhasanxuat" << setw(12) << "Diachikho" << setw(15) << "DongiaTong" << endl;
}
void nhapHangHoa(vector<HangHoa> *hhList)
{ // Menu 1
    int n;
    cout << "Nhap so sp muon nhap: ";
    cin >> n;

    HangHoa temp;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sp thu " << i + 1 << endl;
        temp = inputData(); // Gọi hàm nhập thông tin vào biến tạm sau đó chèn vào vị trí cuối cùng trong vector
        hhList->push_back(temp);
    }
}

void xuatHangHoa(vector<HangHoa> hhList)
{ // Menu 2
    system("cls");
    cout << "Danh sach Hang Hoa" << endl;
    cout << "					" << endl;
    title();
    for (int i = 0; i < hhList.size(); i++)
    {

        cout << hhList[i].maHangHoa << setw(20) << hhList[i].tenHang << setw(13) << hhList[i].soLuong << setw(10) << hhList[i].donGia << setw(10) << hhList[i].nhaSanXuat << setw(13) << hhList[i].diaChikho << setw(15) << hhList[i].tinhDonGiaTong() << endl;
    }
    system("pause");
}

void themHangHoa(vector<HangHoa> *hhList)
{ // Menu 3
    int maHH;
    cout << "Nhap ma hang hoa muon them (nhap 0 de thoat): ";
    cin >> maHH;
    if (maHH == 0)
        return;
    bool found = false;

    for (int i = 0; i < hhList->size() && !found; i++)
        if (maHH == hhList->at(i).maHangHoa)
            found = true;
    if (!found)
    {
        HangHoa temp = inputData();
        hhList->push_back(temp);
    }
    else
    {
        cout << "Ma hang hoa da ton tai" << endl;
        system("pause");
    }
}

void xoaHangHoa(vector<HangHoa> *hhList)
{ // Menu 4
    int maHH;
    cout << "Nhap ma hang hoa muon xoa (nhap 0 de thoat): ";
    cin >> maHH;
    if (maHH == 0)
        return;
    bool found = false;
    for (int i = 0; i < hhList->size(); i++)
    {
        if (hhList->at(i).maHangHoa == maHH)
        {
            hhList->erase(hhList->begin() + i); // Xoá sản phẩm thứ i trong vector
            found = true;
        }
    }
    if (!found)
        cout << "Khong tim thay ma hang hoa" << endl;
    else
        cout << "Xoa thanh cong!" << endl;
    system("pause");
}

void chinhSuaHH(vector<HangHoa> *hhList)
{ // Menu 5
    int maHH;
    cout << "Nhap ma hang hoa muon chinh sua (nhap 0 de thoat): ";
    cin >> maHH;
    if (maHH == 0)
        return;
    bool found = false;
    HangHoa temp;
    for (int i = 0; i < hhList->size(); i++)
    {
        if (hhList->at(i).maHangHoa == maHH)
        {
            temp = inputData(); // Nhập thông tin vào biến tạm sau đó gán lại cho sản phẩm thứ i trong vector
            hhList->at(i).maHangHoa = temp.maHangHoa;
            hhList->at(i).tenHang = temp.tenHang;
            hhList->at(i).soLuong = temp.soLuong;
            hhList->at(i).donGia = temp.donGia;
            hhList->at(i).nhaSanXuat = temp.nhaSanXuat;
            hhList->at(i).diaChikho = temp.diaChikho;
            found = true;
        }
    }
    system("cls");
    if (!found)
        cout << "Khong tim thay ma hang hoa" << endl;
    else
        cout << "Chinh sua thanh cong!" << endl;
    system("pause");
}

void timKiemHangHoa(vector<HangHoa> hhList)
{ // Menu 6
    string tenHang;
    int maHH;
    int timKiem;
    vector<HangHoa> foundList;

    while (true)
    {
        system("cls");
        cout << "\n**********************";
        cout << " MENU TIM KIEM HANG HOA ";
        cout << "************************";
        cout << "\n|                                                                    |";
        cout << "\n|\t1. Tim kiem theo ten hang                                    |" << "\n";
        cout << "| \t2. Tim kiem theo ma hang hoa                                 |" << "\n";
        cout << "| \t3. Thoat                                                     |" << "\n";
        cout << "|                                                                    |" << "\n";
        cout << "**************************************";
        cout << "********************************";
        cout << "\n Nhap lua chon: ";
        cin >> timKiem;

        if (timKiem >= 1 && timKiem <= 3)
            break;
        else
        {
            cout << "Vui long nhap lai" << endl;
            system("pause");
        }
        if (timKiem == 3)
            return;
    }

    if (timKiem == 1)
    {
        cout << "Nhap ten hang muon tim kiem: ";
        cin.ignore();
        getline(cin, tenHang);
        for (int i = 0; i < hhList.size(); i++)
        {
            size_t found = hhList.at(i).tenHang.find(tenHang);
            if (found != std::string::npos)
            {
                foundList.push_back(hhList.at(i));
            }
        }
        if (foundList.size() > 0)
            xuatHangHoa(foundList);
        else
            cout << "Khong tim thay hang hoa" << endl;
        system("pause");
    }
    else
    {
        cout << "Nhap ma hang hoa muon tim kiem: ";
        cin >> maHH;
        for (int i = 0; i < hhList.size(); i++)
        {
            if (hhList.at(i).maHangHoa == maHH)
            {
                foundList.push_back(hhList.at(i));
            }
        }
    }
    system("cls");
    if (foundList.size() == 0)
        cout << "Khong tim thay ma hang hoa" << endl;
    else
    {
        cout << "Tim thay ma hang hoa" << endl;
        xuatHangHoa(foundList);
    }
}

void sapXepHangHoa(vector<HangHoa> *hhList)
{ // Menu 7
    for (int i = 0; i < hhList->size(); i++)
    {
        for (int j = 0; j < hhList->size(); j++)
        {
            if (hhList->at(i).tenHang[0] > hhList->at(j).tenHang[0])
            {
                HangHoa temp = hhList->at(i);
                hhList->at(i) = hhList->at(j);
                hhList->at(j) = temp;
            }
        }
    }
    system("cls");
    cout << "\n Da sap xep!";
    system("pause");
}
void importFile(vector<HangHoa> &hhList)
{
    fstream infile;
    infile.open("ImportData.csv", ios::in);
    if (!infile.is_open())
    {
        cerr << "Khong the mo tep ImportData.csv!" << endl;
        return;
    }

    string line;
    string header;
    getline(infile, header);
    while (getline(infile, line))
    {
        stringstream ss(line);
        string maHangHoaStr, tenHang, soLuongStr, donGiaStr, nhaSanXuat, diaChiKho;
        getline(ss, maHangHoaStr, ',');
        getline(ss, tenHang, ',');
        getline(ss, soLuongStr, ',');
        getline(ss, donGiaStr, ',');
        getline(ss, nhaSanXuat, ',');
        getline(ss, diaChiKho, ',');

        // Chuyển string sang int
        int maHangHoa, soLuong, donGia;
        stringstream(maHangHoaStr) >> maHangHoa;
        stringstream(soLuongStr) >> soLuong;
        stringstream(donGiaStr) >> donGia;

        // Kiểm tra lỗi chuyển đổi
        if (ss.fail())
        {
            cerr << "Loi chuyen doi sang so nguyen!" << endl;
            continue; // Bỏ qua dòng dữ liệu không hợp lệ
        }

        HangHoa hh;
        hh.tenHang = tenHang;
        hh.nhaSanXuat = nhaSanXuat;
        hh.diaChikho = diaChiKho;
        hh.maHangHoa = maHangHoa;
        hh.soLuong = soLuong;
        hh.donGia = donGia;

        hhList.push_back(hh);
    }

    infile.close();
    cout << "Nhap file csv thanh cong!" << endl;
    system("pause");
}
void exportFile(vector<HangHoa> hhList)
{ // Menu 8
    system("cls");
    if (hhList.size() == 0)
    {
        cout << "Khong co san nao!";
        system("pause");
        return;
    }
    fstream outfile;
    outfile.open("ExportData.csv", ios::out);
    outfile << "Ma Hang Hoa,Ten Hang Hoa,So Luong,Don Gia,Nha San Xuat,Dia Chi Kho,Tong Don Gia" << endl;
    for (int i = 0; i < hhList.size(); i++)
    {
        outfile << hhList.at(i).maHangHoa << "," << hhList.at(i).tenHang << "," << hhList.at(i).soLuong << "," << hhList.at(i).donGia << "," << hhList.at(i).nhaSanXuat << "," << hhList.at(i).diaChikho << "," << hhList.at(i).tinhDonGiaTong() << endl;
    }
    outfile.close();
    cout << "Xuat file csv thanh cong" << endl;
    system("pause");
}

int menu()
{
    int chon;
    system("cls");
    cout << "\t    CHAO MUNG DEN VOI CHUONG TRINH QUAN LI HANG HOA";
    cout << "\n                                                                      ";
    cout << "\n********************************";
    cout << " MENU ";
    cout << "********************************";
    cout << "\n|                                                                    |";
    cout << "\n|\t1. Nhap danh sach mat hang                                   |" << "\n";
    cout << "| \t2. Xuat danh sach mat hang                                   |" << "\n";
    cout << "| \t3. Them thong tin 1 mat hang                                 |" << "\n";
    cout << "| \t4. Xoa thong tin 1 mat hang                                  |" << "\n";
    cout << "| \t5. Chinh sua thong tin 1 mat hang                            |" << "\n";
    cout << "| \t6. Tim mat hang                                              |" << "\n";
    cout << "| \t7. Sap xep danh sach mat hang theo tenhang                   |" << "\n";
    cout << "| \t8. Nhap du lieu danh sach mat hang tu file csv               |" << "\n";
    cout << "| \t9. Xuat du lieu danh sach mat hang ra file csv               |" << "\n";
    cout << "| \t10. Thoat                                                    |" << "\n";
    cout << "|                                                                    |" << "\n";
    cout << "**************************************";
    cout << "********************************";
    cout << "\n \t Nhap lua chon: ";
    cin >> chon;
    if (chon < 1 || chon > 10)
    {
        cout << "Vui long nhap lai";
        return menu();
    }
    return chon;
}

int main()
{
    vector<HangHoa> hhList;
    while (true)
    {
        switch (menu())
        {
        case 1:
            nhapHangHoa(&hhList);
            break;
        case 2:
            xuatHangHoa(hhList);
            break;
        case 3:
            themHangHoa(&hhList);
            break;
        case 4:
            xoaHangHoa(&hhList);
            break;
        case 5:
            chinhSuaHH(&hhList);
            break;
        case 6:
            timKiemHangHoa(hhList);
            break;
        case 7:
            sapXepHangHoa(&hhList);
            break;
        case 8:
            importFile(hhList);
            break;
        case 9:
            exportFile(hhList);
            break;
        case 10:
            return 0;
        }
    }
}
