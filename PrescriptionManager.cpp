// PrescriptionManager.cpp
#include "PrescriptionManager.h"
#include "LinkedList.h" // Dùng các hàm của DSLK

Prescription* PrescriptionManager::taoDonThuocMoi(std::string maBN, MedicineManager& medManager) {
    // ... Tạo 1 `Prescription* donMoi` mới
    // ...
    while (nguoiDungMuonThemThuoc) {
        // 1. Nhập `maThuoc`
        // 2. [ỔN ĐỊNH] Kiểm tra xem thuốc có tồn tại không
        MedicineInfo* thuoc = medManager.timThuocTheoMa(maThuoc);
        if (thuoc == NULL) {
            std::cout << "Thuoc khong co trong kho! Moi nhap lai." << std::endl;
            continue;
        }
        
        // 3. Nếu có, tạo 1 `PrescriptionItemNode` mới
        // 4. Gọi `PrescriptionList::insertAtHead(donMoi->head, nodeMoi);`
    }
    return donMoi;
}