// structs.cpp
#include "structs.h"

#include "LinkedList.h"  // <--- File này chứa định nghĩa đầy đủ của PrescriptionList

// Đây là phần định nghĩa của Constructor
Prescription::Prescription() {
  // Bây giờ 'new' là HỢP LỆ,
  // vì C++ đã đọc "LinkedList.h" và biết PrescriptionList là gì.
  this->chiTietThuoc = new PrescriptionList();
}

// Đây là phần định nghĩa của Destructor
Prescription::~Prescription() {
  // 'delete' cũng HỢP LỆ
  delete this->chiTietThuoc;
}