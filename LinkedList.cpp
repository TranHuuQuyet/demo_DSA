// LinkedList.cpp
#include "LinkedList.h"

#include <iostream>

#include "MedicineManager.h"  // Cần để tra cứu tên thuốc khi hiển thị
#include "structs.h"

// Constructor: Khởi tạo head = NULL
PrescriptionList::PrescriptionList() { this->head = NULL; }

// Destructor: Tự động gọi freeList
PrescriptionList::~PrescriptionList() { this->freeList(); }

//CHỨC NĂNG Thêm vào đầu
void PrescriptionList::insertAtHead(string maThuoc, int soLuong,
                                    string huongDan) {
  // 1. Tạo node mới
  PrescriptionItemNode* newNode =
      new PrescriptionItemNode();  // tạo một bộ nhớ trên heap kiểu prescription
  newNode->maThuoc = maThuoc;
  newNode->soLuong = soLuong;
  newNode->huongDanSuDung = huongDan;

  // 2. Nối vào đầu
  newNode->next = this->head;

  // 3. Cập nhật head
  this->head = newNode;
}

// CHỨC NĂNG Dọn dẹp bộ nhớ
void PrescriptionList::freeList() {
  PrescriptionItemNode* current = this->head;
  while (current != NULL) {
    PrescriptionItemNode* temp = current;  // Giữ node tạm
    current = current->next;               // Di chuyển
    delete temp;                           // Xóa node
  }
  this->head = NULL;  // Đảm bảo an toàn
}

// CHỨC NĂNG Hiển thị (ví dụ)
void PrescriptionList::display(const MedicineManager& medManager) {
  PrescriptionItemNode* current = this->head;
  if (current == NULL) {
    cout << "  (Don thuoc rong !)" << endl;
    return;
  }

  int i = 1;
  while (current != NULL) {
    // Tra cứu tên thuốc từ Bảng Băm
    // Lưu ý: hàm find() phải là 'const' hoặc phải ép kiểu
    MedicineInfo* info = medManager.timThuocTheoMa(current->maThuoc);

    cout << "  " << i++ << ". ";
    if (info != NULL) {
      cout << info->tenThuoc;
    } else {
      cout << current->maThuoc << " (Khong ro ten)";
    }
    cout << " - SL: " << current->soLuong <<endl;
    cout << "     HD: " << current->huongDanSuDung <<endl;

    current = current->next;
  }
}