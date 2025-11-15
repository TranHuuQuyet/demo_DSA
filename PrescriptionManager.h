// PrescriptionManager.h
#pragma once
#include "structs.h"       // Cần struct Prescription
#include "MedicineManager.h" // Cần để kiểm tra thuốc
#include <string>

// --- Định nghĩa Node cho DSLK các Đơn thuốc ---
// Node này quản lý danh sách TẤT CẢ các đơn thuốc trong hệ thống
struct PrescriptionListNode {
    Prescription* data; // Dữ liệu là một con trỏ tới Đơn thuốc
    PrescriptionListNode* next;
};

// --- Class Quản lý ---
class PrescriptionManager {
private:
    // Đầu danh sách liên kết, lưu trữ TẤT CẢ đơn thuốc
    PrescriptionListNode* head; 

public:
    // Constructor: Khởi tạo head = NULL
    PrescriptionManager();

    // Destructor: Dọn dẹp TOÀN BỘ đơn thuốc
    ~PrescriptionManager();

    /**
     * Tạo một đơn thuốc mới, đồng thời LƯU VÀO danh sách quản lý
     * (Hàm này sẽ gọi hàm nhập từ bàn phím)
     */
    void taoDonThuocMoi(std::string maDonThuoc, std::string maBN, MedicineManager& medManager);

    /**
     * Tìm một đơn thuốc theo mã
     */
    Prescription* timDonThuoc(std::string maDonThuoc) const;
    
    /**
     * Hiển thị chi tiết MỘT đơn thuốc (dùng sau khi tìm)
     * (Đây chính là hàm 'hienThiDonThuoc' cũ của bạn)
     */
    void hienThiChiTietDonThuoc(const Prescription* donThuoc, const MedicineManager& medManager) const;
    
    /**
     * Hiển thị danh sách TẤT CẢ đơn thuốc (dạng tóm tắt)
     */
    void hienThiTatCaDonThuoc() const;

private:
    /**
     * Hàm private để dọn dẹp bộ nhớ (sẽ được gọi bởi Destructor)
     */
    void freeList();
};