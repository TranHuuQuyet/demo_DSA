// structs.h
#pragma once
#include <string>

// 1. Dữ liệu cho Bảng Băm (Kho thuốc)
struct MedicineInfo {
    std::string maThuoc;
    std::string tenThuoc;
    std::string donViTinh;
    double donGia;
};

// 2. Dữ liệu cho Danh sách Liên kết (Thuốc trong 1 đơn)
struct PrescriptionItemNode {
    std::string maThuoc;
    int soLuong;
    std::string huongDanSuDung;
    PrescriptionItemNode* next;
};

// Khai báo trước (forward declaration)
class PrescriptionList; 

// 3. Dữ liệu cho Đơn thuốc (Quản lý các DSLK)
struct Prescription {
    std::string maDonThuoc;
    std::string maBenhNhan;
    std::string ngayKeDon;
    
    PrescriptionList* chiTietThuoc; // Dùng con trỏ để quản lý

    // Chỉ KHAIBÁO
    Prescription();
    ~Prescription();
};