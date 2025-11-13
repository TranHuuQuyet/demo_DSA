// MedicineManager.h
#pragma once
#include "HashTable.h"

class MedicineManager {
private:
    HashTable* khoThuoc; // Sử dụng con trỏ

public:
    MedicineManager();
    ~MedicineManager();
    
    bool themThuocMoi(std::string ma, std::string ten, ...);
    void capNhatThuoc(std::string ma);
    MedicineInfo* timThuocTheoMa(std::string ma); // Hàm "wrapper"
};