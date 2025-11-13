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

// 3. Dữ liệu cho Đơn thuốc (Quản lý các DSLK)
struct Prescription {
    std::string maDonThuoc;
    std::string maBenhNhan;
    std::string ngayKeDon;
    PrescriptionItemNode* head; // Đầu danh sách liên kết các thuốc
    // ...
};