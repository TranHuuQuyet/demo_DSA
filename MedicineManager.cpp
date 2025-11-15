// MedicineManager.cpp
#include "MedicineManager.h"
#include <iostream> // <--- BẮT BUỘC PHẢI THÊM

// 1. Constructor: Đã làm tốt
MedicineManager::MedicineManager() {
    this->khoThuoc = new HashTable(100); // Khởi tạo kho thuốc với 100 "xô"
}

// 2. Destructor: Đã làm tốt
MedicineManager::~MedicineManager() {
    delete this->khoThuoc; // Tự động gọi Destructor của HashTable
}

/**
 * 3. [BỔ SUNG] Hàm thêm thuốc mới
 */
bool MedicineManager::themThuocMoi(std::string ma, std::string ten, std::string donViTinh, double donGia) {
    // 1. Kiểm tra xem thuốc đã tồn tại chưa
    if (this->khoThuoc->find(ma) != NULL) {
        std::cout << "Loi: Ma thuoc " << ma << " da ton tai." << std::endl;
        return false; // Thêm thất bại
    }

    // 2. Tạo đối tượng MedicineInfo mới
    MedicineInfo newMedicine;
    newMedicine.maThuoc = ma;
    newMedicine.tenThuoc = ten;
    newMedicine.donViTinh = donViTinh;
    newMedicine.donGia = donGia;

    // 3. Thêm vào Bảng Băm
    this->khoThuoc->insert(newMedicine);
    return true; // Thêm thành công
}

/**
 * 4. [BỔ SUNG] Hàm cập nhật thuốc
 */
bool MedicineManager::capNhatThuoc(std::string ma, std::string tenMoi, std::string dvtMoi, double giaMoi) {
    // 1. Cập nhật bằng cách gọi hàm insert
    //    (Vì hàm insert của HashTable chúng ta đã thiết kế để
    //     tự động cập nhật nếu tìm thấy)
    
    // Tạo đối tượng với thông tin mới
    MedicineInfo updatedMedicine;
    updatedMedicine.maThuoc = ma;
    updatedMedicine.tenThuoc = tenMoi;
    updatedMedicine.donViTinh = dvtMoi;
    updatedMedicine.donGia = giaMoi;

    // Gọi insert. Hàm này sẽ tìm 'ma' và ghi đè thông tin.
    this->khoThuoc->insert(updatedMedicine);
    
    // Lưu ý: Cần kiểm tra xem 'ma' có tồn tại không,
    // nhưng hàm 'insert' của chúng ta đã xử lý việc này (vừa tìm vừa cập nhật).
    return true;
}

/**
 * 5. [BỔ SUNG] Hàm xóa thuốc
 */
void MedicineManager::xoaThuoc(std::string ma) {
    this->khoThuoc->remove(ma);
}

/**
 * 6. Hàm tìm thuốc: Gần như hoàn hảo
 */
MedicineInfo* MedicineManager::timThuocTheoMa(std::string ma) const {
    MedicineInfo* result = this->khoThuoc->find(ma);
    
    // Góp ý nhỏ: Không nên 'cout' trong hàm tìm kiếm.
    // Hàm tìm kiếm chỉ nên trả về NULL.
    // Nơi gọi hàm (ví dụ: main) sẽ kiểm tra NULL và in lỗi.
    if (result == NULL) {
        // Xóa dòng cout này đi thì code sẽ "sạch" hơn
        // std::cout << "Loi: Khong tim thay thuoc voi ma " << ma << std::endl; 
        return NULL;
    }
    return result;
}