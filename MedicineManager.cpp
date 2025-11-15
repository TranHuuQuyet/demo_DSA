// MedicineManager.cpp
#include "MedicineManager.h"
#include <iostream> // Thêm include

// 1. Constructor
MedicineManager::MedicineManager() {
    this->khoThuoc = new HashTable(100);
}

// 2. Destructor
MedicineManager::~MedicineManager() {
    delete this->khoThuoc;
}

// 3. Thêm thuốc
bool MedicineManager::themThuocMoi(std::string ma, std::string ten, std::string donViTinh, double donGia) {
    if (this->khoThuoc->find(ma) != NULL) {
        std::cout << "Loi: Ma thuoc " << ma << " da ton tai." << std::endl;
        return false;
    }
    MedicineInfo newMedicine;
    newMedicine.maThuoc = ma;
    newMedicine.tenThuoc = ten;
    newMedicine.donViTinh = donViTinh;
    newMedicine.donGia = donGia;
    this->khoThuoc->insert(newMedicine);
    return true;
}

// 4. Cập nhật
bool MedicineManager::capNhatThuoc(std::string ma, std::string tenMoi, std::string dvtMoi, double giaMoi) {
    // Tận dụng hàm 'insert' để cập nhật
    MedicineInfo updatedMedicine;
    updatedMedicine.maThuoc = ma;
    updatedMedicine.tenThuoc = tenMoi;
    updatedMedicine.donViTinh = dvtMoi;
    updatedMedicine.donGia = giaMoi;
    this->khoThuoc->insert(updatedMedicine);
    return true;
}

// 5. Xóa thuốc
void MedicineManager::xoaThuoc(std::string ma) {
    this->khoThuoc->remove(ma);
}

// 6. Tìm thuốc (const)
MedicineInfo* MedicineManager::timThuocTheoMa(std::string ma) const {
    MedicineInfo* result = this->khoThuoc->find(ma);
    // Không nên in lỗi ở đây, để cho nơi gọi xử lý
    return result; 
}