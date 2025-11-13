// PrescriptionManager.h
#pragma once
#include "structs.h"
#include "MedicineManager.h" // Cần để kiểm tra thuốc

class PrescriptionManager {
private:
    // ... Có thể lưu danh sách các đơn thuốc ở đây (ví dụ: 1 DSLK khác)
public:
    Prescription* taoDonThuocMoi(std::string maBN, MedicineManager& medManager);
    void hienThiDonThuoc(Prescription* donThuoc, MedicineManager& medManager);
};