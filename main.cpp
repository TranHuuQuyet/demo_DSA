// main.cpp
#include <iostream>
#include <string>
#include <limits> // Cần cho cin.ignore()

#include "MedicineManager.h"
#include "PrescriptionManager.h"

// Khai báo các hàm hỗ trợ (để giữ cho 'main' sạch sẽ)
void displayMenu();
void xuLyThemThuoc(MedicineManager& qlKho);
void xuLyCapNhatThuoc(MedicineManager& qlKho);
void xuLyTaoDonThuoc(PrescriptionManager& qlDon, MedicineManager& qlKho);
void xuLyTimDonThuoc(const PrescriptionManager& qlDon, const MedicineManager& qlKho);

int main() {
    // 1. Khởi tạo các hệ thống quản lý
    // Constructor của chúng sẽ tự động chạy
    MedicineManager quanLyKho;
    PrescriptionManager quanLyDon;
    
    // 2. Nạp dữ liệu ban đầu (Sửa lỗi '...' của bạn)
    std::cout << "Dang nap du lieu kho thuoc ban dau..." << std::endl;
    quanLyKho.themThuocMoi("P001", "Paracetamol 500mg", "Vien", 1000.0);
    quanLyKho.themThuocMoi("A025", "Amoxicillin 250mg", "Vien", 3000.0);
    quanLyKho.themThuocMoi("S010", "Salbutamol 2mg", "Chai", 15000.0);
    std::cout << "Nap du lieu xong." << std::endl;

    int choice;
    do {
        displayMenu();
        std::cout << "Nhap lua chon cua ban: ";
        
        // Kiểm tra nhập liệu
        while (!(std::cin >> choice)) {
            std::cout << "Nhap sai, vui long nhap mot SO: ";
            std::cin.clear(); // Xóa cờ lỗi
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa bộ đệm
        }
        
        // Xóa bộ đệm sau khi nhập số, trước khi dùng getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            case 1:
                // 1. Thêm thuốc vào kho
                xuLyThemThuoc(quanLyKho);
                break;
            case 2:
                // 2. Cập nhật thuốc
                xuLyCapNhatThuoc(quanLyKho);
                break;
            case 3:
                // 3. Tạo đơn thuốc mới
                //    (Truyền 'quanLyKho' vào để kiểm tra thuốc)
                xuLyTaoDonThuoc(quanLyDon, quanLyKho);
                break;
            case 4:
                // 4. Tìm và hiển thị một đơn thuốc
                xuLyTimDonThuoc(quanLyDon, quanLyKho);
                break;
            case 5:
                // 5. Hiển thị tóm tắt TẤT CẢ đơn thuốc
                quanLyDon.hienThiTatCaDonThuoc();
                break;
            case 0:
                std::cout << "Tam biet!" << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long chon lai." << std::endl;
                break;
        }
        std::cout << "\nNhan Enter de tiep tuc...";
        std::cin.get(); // Chờ người dùng

    } while (choice != 0);

    return 0;
    // KHI 'main' KẾT THÚC:
    // Destructor của 'quanLyDon' và 'quanLyKho' sẽ TỰ ĐỘNG được gọi.
    // Toàn bộ bộ nhớ sẽ được dọn dẹp sạch sẽ.
}

// --- Cài đặt các hàm hỗ trợ ---

void displayMenu() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "   HE THONG QUAN LY DON THUOC CO BAN   " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Them thuoc moi vao kho" << std::endl;
    std::cout << "2. Cap nhat thong tin thuoc" << std::endl;
    std::cout << "3. Tao don thuoc moi" << std::endl;
    std::cout << "4. Tim va hien thi don thuoc" << std::endl;
    std::cout << "5. Hien thi tat ca don thuoc" << std::endl;
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
    // (Hàm themThuocMoi đã tự in lỗi nếu thất bại)
}

void xuLyCapNhatThuoc(MedicineManager& qlKho) {
    std::string ma, tenMoi, dvtMoi;
    double giaMoi;

    std::cout << "--- Cap nhat thuoc ---" << std::endl;
    std::cout << "Nhap Ma thuoc can cap nhat: ";
    std::getline(std::cin, ma);

    // Kiểm tra xem thuốc có tồn tại không
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

    // Ủy quyền toàn bộ logic phức tạp cho Manager
    // Hàm này sẽ tự động chạy vòng lặp nhập thuốc
    qlDon.taoDonThuocMoi(maDon, maBN, qlKho);
}

void xuLyTimDonThuoc(const PrescriptionManager& qlDon, const MedicineManager& qlKho) {
    std::string maDon;
    std::cout << "--- Tim kiem don thuoc ---" << std::endl;
    std::cout << "Nhap Ma don thuoc can tim: ";
    std::getline(std::cin, maDon);

    // 1. Tìm đơn thuốc
    Prescription* donThuoc = qlDon.timDonThuoc(maDon);

    // 2. Kiểm tra kết quả
    if (donThuoc == NULL) {
        std::cout << "Loi: Khong tim thay don thuoc voi ma " << maDon << std::endl;
    } else {
        // 3. Nếu thấy, hiển thị chi tiết
        std::cout << "Da tim thay don thuoc!" << std::endl;
        qlDon.hienThiChiTietDonThuoc(donThuoc, qlKho);
    }
}