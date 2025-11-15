// structs.cpp
#include "structs.h"
#include "LinkedList.h" // Cần file này để có định nghĩa đầy đủ

// Đây là phần định nghĩa của Constructor
Prescription::Prescription() {
    // Bây giờ 'new' là HỢP LỆ
    this->chiTietThuoc = new PrescriptionList(); 
}

// Đây là phần định nghĩa của Destructor
Prescription::~Prescription() {
    // 'delete' cũng HỢP LỆ
    delete this->chiTietThuoc; 
}