// structs.h
#pragma once // Đảm bảo file chỉ được include 1 lần
#include <string>

// 1. Dữ liệu cho Bảng Băm (Kho thuốc)
struct MedicineInfo {
    std::string maThuoc;
    std::string tenThuoc;
    std::string donViTinh;
    double donGia;
    // ... các thông tin khác
};

// 2. Dữ liệu cho Danh sách Liên kết (Thuốc trong 1 đơn)
struct PrescriptionItemNode {
    std::string maThuoc; // Dùng để tra cứu trong Bảng Băm
    int soLuong;
    std::string huongDanSuDung;
    PrescriptionItemNode* next;
};
// *************************************************************
// CHÚ Ý: Đặt struct PrescriptionList ở file riêng "LinkedList.h"
// Chúng ta cần "khai báo trước" (forward declaration) để tránh lỗi include vòng lặp
struct PrescriptionList; // Báo cho C++ biết "sẽ có 1 struct tên này"
// *************************************************************
// 3. Dữ liệu cho Đơn thuốc (Quản lý các DSLK)
struct Prescription {
    std::string maDonThuoc;
    std::string maBenhNhan;
    std::string ngayKeDon;
    // PrescriptionItemNode* head; // Đầu danh sách liên kết các thuốc

    // THAY ĐỔI LỚN Ở ĐÂY
    // Thay vì: PrescriptionItemNode* head;
    // Dùng:
    PrescriptionList* chiTietThuoc; // Dùng con trỏ để quản lý
    // hoặc PrescriptionList chiTietThuoc; // Dùng đối tượng trực tiếp

    // ...
    // Constructor cho Prescription để khởi tạo chiTietThuoc
    Prescription() {
        chiTietThuoc = new PrescriptionList(); // Nếu dùng con trỏ
    }
    // Destructor cho Prescription để hủy chiTietThuoc
    ~Prescription() {
        delete chiTietThuoc; // Nếu dùng con trỏ
    }
    // ...
};