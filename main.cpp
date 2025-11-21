// main.cpp
#include <iostream>
#include <string>
#include <limits> 

#include "MedicineManager.h"
#include "PrescriptionManager.h"

// Khai báo các hàm hỗ trợ
void displayMenu();
void xuLyThemThuoc(MedicineManager& qlKho);
void xuLyCapNhatThuoc(MedicineManager& qlKho);
void xuLyTaoDonThuoc(PrescriptionManager& qlDon, MedicineManager& qlKho);
void xuLyTimDonThuoc(const PrescriptionManager& qlDon, const MedicineManager& qlKho);

int main() {
    MedicineManager quanLyKho;
    PrescriptionManager quanLyDon;
    
    std::cout << "Dang nap du lieu kho thuoc ban dau..." << std::endl;
    quanLyKho.themThuocMoi("P001", "Paracetamol 500mg", "Vien", 1000.0);
    quanLyKho.themThuocMoi("A025", "Amoxicillin 250mg", "Vien", 3000.0);
    quanLyKho.themThuocMoi("S010", "Salbutamol 2mg", "Chai", 15000.0);
    std::cout << "Nap du lieu xong." << std::endl;

    int choice;
    do {
        displayMenu();
        std::cout << "Nhap lua chon cua ban: ";
        
        while (!(std::cin >> choice)) {
            std::cout << "Nhap sai, vui long nhap mot SO: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            case 1:
                xuLyThemThuoc(quanLyKho);
                break;
            case 2:
                xuLyCapNhatThuoc(quanLyKho);
                break;
            case 3:
                xuLyTaoDonThuoc(quanLyDon, quanLyKho);
                break;
            case 4:
                xuLyTimDonThuoc(quanLyDon, quanLyKho);
                break;
            case 5:
                quanLyDon.hienThiTatCaDonThuoc();
                break;
            case 6:
            quanLyKho.display();
            case 0:
                std::cout << "Tam biet!" << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long chon lai." << std::endl;
                break;
        }
        if (choice != 0) {
             std::cout << "\n(Nhan Enter de tiep tuc...)";
             std::cin.get();
        }

    } while (choice != 0);

    return 0;
}

// --- Cài đặt các hàm hỗ trợ ---

void displayMenu() {
    system("cls"); // Xóa màn hình (Windows)
    // system("clear"); // Xóa màn hình (Linux/macOS)
    std::cout << "\n========================================" << std::endl;
    std::cout << "   HE THONG QUAN LY DON THUOC CO BAN   " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Them thuoc moi vao kho" << std::endl;
    std::cout << "2. Cap nhat thong tin thuoc" << std::endl;
    std::cout << "3. Tao don thuoc moi" << std::endl;
    std::cout << "4. Tim va hien thi don thuoc" << std::endl;
    std::cout << "5. Hien thi tat ca don thuoc" << std::endl;
    std::cout << "6. Hien thi tat ca thuoc trong kho" << std::endl;
    std::cout << "0. Thoat" << std::endl;
    std::cout << "========================================" << std::endl;
}

void xuLyThemThuoc(MedicineManager& qlKho) {
    std::string ma, ten, dvt;
    double gia;
    std::cout << "--- Them thuoc moi ---" << std::endl;
    std::cout << "Nhap Ma thuoc: ";
    std::getline(std::cin, ma);
    std::cout << "Nhap Ten thuoc: ";
    std::getline(std::cin, ten);
    std::cout << "Nhap Don vi tinh: ";
    std::getline(std::cin, dvt);
    std::cout << "Nhap Don gia: ";
    std::cin >> gia;
    if (qlKho.themThuocMoi(ma, ten, dvt, gia)) {
        std::cout << "Them thuoc thanh cong!" << std::endl;
    }
}

void xuLyCapNhatThuoc(MedicineManager& qlKho) {
    std::string ma, tenMoi, dvtMoi;
    double giaMoi;
    std::cout << "--- Cap nhat thuoc ---" << std::endl;
    std::cout << "Nhap Ma thuoc can cap nhat: ";
    std::getline(std::cin, ma);

    MedicineInfo* thuoc = qlKho.timThuocTheoMa(ma);
    if (thuoc == NULL) {
        std::cout << "Loi: Khong tim thay thuoc voi ma " << ma << std::endl;
        return;
    }
    std::cout << "  -> Da tim thay: " << thuoc->tenThuoc << " (Gia: " << thuoc->donGia << ")" << std::endl;
    std::cout << "Nhap Ten thuoc MOI: ";
    std::getline(std::cin, tenMoi);
    std::cout << "Nhap Don vi tinh MOI: ";
    std::getline(std::cin, dvtMoi);
    std::cout << "Nhap Don gia MOI: ";
    std::cin >> giaMoi;
    if (qlKho.capNhatThuoc(ma, tenMoi, dvtMoi, giaMoi)) {
        std::cout << "Cap nhat thuoc thanh cong!" << std::endl;
    }
}

void xuLyTaoDonThuoc(PrescriptionManager& qlDon, MedicineManager& qlKho) {
    std::string maDon, maBN;
    std::cout << "--- Tao don thuoc moi ---" << std::endl;
    std::cout << "Nhap Ma don thuoc (vi du: DT001): ";
    std::getline(std::cin, maDon);
    std::cout << "Nhap Ma Benh nhan (vi du: BN123): ";
    std::getline(std::cin, maBN);
    
    qlDon.taoDonThuocMoi(maDon, maBN, qlKho);
}

void xuLyTimDonThuoc(const PrescriptionManager& qlDon, const MedicineManager& qlKho) {
    std::string maDon;
    std::cout << "--- Tim kiem don thuoc ---" << std::endl;
    std::cout << "Nhap Ma don thuoc can tim: ";
    std::getline(std::cin, maDon);
    Prescription* donThuoc = qlDon.timDonThuoc(maDon);
    if (donThuoc == NULL) {
        std::cout << "Loi: Khong tim thay don thuoc voi ma " << maDon << std::endl;
    } else {
        std::cout << "Da tim thay don thuoc!" << std::endl;
        qlDon.hienThiChiTietDonThuoc(donThuoc, qlKho);
    }
}