// LinkedList.cpp
#include "LinkedList.h"
#include "structs.h"         // Cần để tạo new PrescriptionItemNode
#include "MedicineManager.h" // Cần để dùng hàm timThuocTheoMa
#include <iostream>

// Constructor
PrescriptionList::PrescriptionList() {
    this->head = NULL;
}

// Destructor
PrescriptionList::~PrescriptionList() {
    this->freeList();
}

// Hàm private: Dọn dẹp bộ nhớ
void PrescriptionList::freeList() {
    PrescriptionItemNode* current = this->head;
    while (current != NULL) {
        PrescriptionItemNode* temp = current;
        current = current->next;
        delete temp;
    }
    this->head = NULL;
}

// Hàm public: Thêm vào đầu
void PrescriptionList::insertAtHead(std::string maThuoc, int soLuong, std::string huongDan) {
    PrescriptionItemNode* newNode = new PrescriptionItemNode();
    newNode->maThuoc = maThuoc;
    newNode->soLuong = soLuong;
    newNode->huongDanSuDung = huongDan;

    newNode->next = this->head;
    this->head = newNode;
}

// Hàm public: Hiển thị (đã có const)
void PrescriptionList::display(const MedicineManager& medManager) const {
    PrescriptionItemNode* current = this->head;
    if (current == NULL) {
        std::cout << "  (Don thuoc rong !)" << std::endl;
        return;
    }

    int i = 1;
    while (current != NULL) {
        // Tra cứu tên thuốc (KHÔNG CẦN const_cast nữa)
        MedicineInfo* info = medManager.timThuocTheoMa(current->maThuoc);
        
        std::cout << "  " << i++ << ". ";
        if (info != NULL) {
            std::cout << info->tenThuoc;
        } else {
            std::cout << current->maThuoc << " (Khong ro ten)";
        }
        std::cout << " - SL: " << current->soLuong << std::endl;
        std::cout << "     HD: " << current->huongDanSuDung << std::endl;
        
        current = current->next;
    }
}