// MedicineManager.h
#pragma once
#include "HashTable.h" // Cần để biết class HashTable
#include "structs.h"   // Cần để biết struct MedicineInfo
#include <string>      // Cần cho std::string

class MedicineManager {
private:
    HashTable* khoThuoc; // Sử dụng con trỏ

public:
    MedicineManager(); // Sẽ 'new' khoThuoc
    ~MedicineManager(); // Sẽ 'delete' khoThuoc
    
    /**
     * Sửa lỗi '...'
     * Cung cấp đầy đủ các tham số cần thiết để tạo một MedicineInfo.
     */
    bool themThuocMoi(std::string ma, std::string ten, std::string donViTinh, double donGia);

    /**
     * Cập nhật thông tin thuốc.
     * Hàm này sẽ tìm thuốc theo 'ma' và cập nhật các thông tin còn lại.
     */
    bool capNhatThuoc(std::string ma, std::string tenMoi, std::string dvtMoi, double giaMoi);

    /**
     * Xóa thuốc khỏi kho.
     */
    void xoaThuoc(std::string ma);

    /**
     * Hàm "wrapper" (bọc lại)
     * Đã được đánh dấu 'const' -> Rất tốt!
     */
    MedicineInfo* timThuocTheoMa(std::string ma) const;
};