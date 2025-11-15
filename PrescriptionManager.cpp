// PrescriptionManager.cpp
#include "PrescriptionManager.h"
#include "LinkedList.h" // Cần để gọi chiTietThuoc->insert...
#include <iostream>
#include <string>

// 1. Constructor
PrescriptionManager::PrescriptionManager() {
    this->head = NULL;
}

// 2. Destructor
PrescriptionManager::~PrescriptionManager() {
    this->freeList();
}

// 3. Hàm dọn dẹp private
void PrescriptionManager::freeList() {
    PrescriptionListNode* current = this->head;
    while (current != NULL) {
        PrescriptionListNode* temp = current;
        current = current->next;
        delete temp->data; // Kích hoạt ~Prescription()
        delete temp;       // Xóa node quản lý
    }
    this->head = NULL;
}

// 4. Tạo đơn thuốc mới
void PrescriptionManager::taoDonThuocMoi(std::string maDonThuoc, std::string maBN, MedicineManager& medManager) {
    if (this->timDonThuoc(maDonThuoc) != NULL) {
        std::cout << "Loi: Ma don thuoc " << maDonThuoc << " da ton tai." << std::endl;
        return;
    }

    Prescription* donMoi = new Prescription();
    donMoi->maDonThuoc = maDonThuoc;
    donMoi->maBenhNhan = maBN;
    
    std::cout << "--- Bat dau nhap thuoc cho don " << maDonThuoc << " ---" << std::endl;
    std::string maThuoc;
    while (true) {
        std::cout << "Nhap ma thuoc (nhap 'xong' de ket thuc): ";
        std::getline(std::cin, maThuoc);
        if (maThuoc == "xong") {
            break;
        }

        MedicineInfo* thuoc = medManager.timThuocTheoMa(maThuoc);
        if (thuoc == NULL) {
            std::cout << "Loi: Khong tim thay thuoc. Vui long nhap lai." << std::endl;
            continue;
        }

        int soLuong;
        std::string huongDan;
        std::cout << "  -> Da tim thay: " << thuoc->tenThuoc << std::endl;
        std::cout << "  -> Nhap so luong: ";
        while (!(std::cin >> soLuong)) {
             std::cout << "Nhap sai, vui long nhap SO: ";
             std::cin.clear();
             std::cin.ignore(1000, '\n');
        }
        std::cin.ignore(1000, '\n'); // Xóa bộ đệm
        std::cout << "  -> Nhap huong dan: ";
        std::getline(std::cin, huongDan);

        donMoi->chiTietThuoc->insertAtHead(maThuoc, soLuong, huongDan);
        std::cout << "  -> Da them thuoc vao don." << std::endl;
    }

    // Lưu đơn thuốc vào danh sách quản lý
    PrescriptionListNode* newNode = new PrescriptionListNode();
    newNode->data = donMoi;
    newNode->next = this->head;
    this->head = newNode;

    std::cout << "--- Da tao va luu don thuoc " << maDonThuoc << " thanh cong! ---" << std::endl;
}

// 5. Tìm đơn thuốc
Prescription* PrescriptionManager::timDonThuoc(std::string maDonThuoc) const {
    PrescriptionListNode* current = this->head;
    while (current != NULL) {
        if (current->data->maDonThuoc == maDonThuoc) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

// 6. Hiển thị chi tiết
void PrescriptionManager::hienThiChiTietDonThuoc(const Prescription* donThuoc, const MedicineManager& medManager) const {
    if (donThuoc == NULL) {
        std::cout << "Loi: Don thuoc la NULL." << std::endl;
        return;
    }
    std::cout << "========================================" << std::endl;
    std::cout << "MA DON THUOC: " << donThuoc->maDonThuoc << std::endl;
    std::cout << "BENH NHAN:    " << donThuoc->maBenhNhan << std::endl;
    std::cout << "NGAY KE:      " << donThuoc->ngayKeDon << std::endl;
    std::cout << "--- CHI TIET THUOC ---" << std::endl;
    donThuoc->chiTietThuoc->display(medManager);
    std::cout << "========================================" << std::endl;
}

// 7. Hiển thị tất cả
void PrescriptionManager::hienThiTatCaDonThuoc() const {
    std::cout << "--- DANH SACH TAT CA DON THUOC ---" << std::endl;
    PrescriptionListNode* current = this->head;
    if (current == NULL) {
        std::cout << "(Chua co don thuoc nao)" << std::endl;
        return;
    }
    int i = 1;
    while (current != NULL) {
        std::cout << i++ << ". Ma Don: " << current->data->maDonThuoc
                  << ", BN: " << current->data->maBenhNhan << std::endl;
        current = current->next;
    }
}