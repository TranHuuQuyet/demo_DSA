// MedicineManager.cpp
#include "MedicineManager.h"

MedicineManager::MedicineManager() {
    this->khoThuoc = new HashTable(100); // Khởi tạo kho thuốc với 100 "xô"
}

MedicineManager::~MedicineManager() {
    delete this->khoThuoc; // Tự động gọi Destructor của HashTable
}

MedicineInfo* MedicineManager::timThuocTheoMa(std::string ma) const {
    // [ỔN ĐỊNH] Luôn kiểm tra NULL
    MedicineInfo* result = this->khoThuoc->find(ma);
    if (result == NULL) {
        std::cout << "Loi: Khong tim thay thuoc voi ma " << ma << std::endl;
        return NULL;
    }
    return result;
}