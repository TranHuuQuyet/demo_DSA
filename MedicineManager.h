// MedicineManager.h
#pragma once
#include "Hashtable.h"
#include "structs.h"
#include <string>

class MedicineManager {
private:
    HashTable* khoThuoc; 

public:
    MedicineManager();
    ~MedicineManager();
    
    bool themThuocMoi(std::string ma, std::string ten, std::string donViTinh, double donGia);
    bool capNhatThuoc(std::string ma, std::string tenMoi, std::string dvtMoi, double giaMoi);
    void xoaThuoc(std::string ma);

    // Đã có 'const'
    MedicineInfo* timThuocTheoMa(std::string ma) const;
    void display() const;
};