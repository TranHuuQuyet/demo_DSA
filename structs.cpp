// structs.cpp
#include "structs.h" // include file để có được các định nghĩa về class/struct trước đó 
#include "LinkedList.h" // Cần file này để có định nghĩa đầy đủ

// Đây là phần định nghĩa của Constructor
Prescription::Prescription() {
    // Bây giờ 'new' là HỢP LỆ
    this->chiTietThuoc = new PrescriptionList(); 
// câp phát đông một đối tượng prescriptionlist trong heap và gán cho chitietthuoc
}
// Đây là phần định nghĩa của Destructor
Prescription::~Prescription() {
    // 'delete' cũng HỢP LỆ
    delete this->chiTietThuoc; 
    // xóa hết node trong Linked list và giải phòng vùng nhớ mà prescriptionList đang giữ
}