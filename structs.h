// structs.h
#pragma once // đảm bảo file chỉ được include 1 lần 
#include <string> //  khai báo thư viện string

// 1. Dữ liệu cho Bảng Băm (Kho thuốc)
struct MedicineInfo { //khai báo các thuộc tính của 1 loại thuốc sử dụng bảng băm
    std::string maThuoc; // mã thuốc
    std::string tenThuoc; // tên thuốc
    std::string donViTinh; // đơn vị tính
    double donGia; // đơn giá
};

// 2. Dữ liệu cho Danh sách Liên kết (Thuốc trong 1 đơn)
struct PrescriptionItemNode { // khai báo thuộc tính của 1 loại thuốc trong đơn dùng Linked list
    std::string maThuoc; // mã thuốc
    int soLuong; // số lượng
    std::string huongDanSuDung; // hướng dẫn sử dụng
    PrescriptionItemNode* next; // con trỏ để trỏ dến thuốc tiếp theo trong 1 đơn
};

// Khai báo trước (forward declaration)
class PrescriptionList; // khai báo để sử dụng con trỏ 

// 3. Dữ liệu cho Đơn thuốc (Quản lý các DSLK)
struct Prescription { // khai báo thuộc tính của 1 đơn thuốc
    std::string maDonThuoc; // mã đơn thuốc
    std::string maBenhNhan; // mã bệnh nhân
    std::string ngayKeDon; // ngày kê đơn
    
    PrescriptionList* chiTietThuoc; // Dùng con trỏ để quản lý

    // Chỉ KHAIBÁO
    Prescription(); // Contructor khởi tạo giá trị ban đầu
    ~Prescription(); // Destructor hàm hủy và giải phóng tài nguyên
};