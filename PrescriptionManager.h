// PrescriptionManager.h
#pragma once
#include "structs.h"       
#include "MedicineManager.h" 
#include <string>

// Node quản lý TẤT CẢ các đơn thuốc
struct PrescriptionListNode {
    Prescription* data; 
    PrescriptionListNode* next;
};

class PrescriptionManager {
private:
    PrescriptionListNode* head; 
    void freeList(); // Hàm dọn dẹp private

public:
    PrescriptionManager();
    ~PrescriptionManager();

    void taoDonThuocMoi(std::string maDonThuoc, std::string maBN, MedicineManager& medManager);
    Prescription* timDonThuoc(std::string maDonThuoc) const;
    void hienThiChiTietDonThuoc(const Prescription* donThuoc, const MedicineManager& medManager) const;
    void hienThiTatCaDonThuoc() const;
};