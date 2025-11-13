// LinkedList.h
#pragma once
#include "structs.h" // Cần file này để biết PrescriptionItemNode là gì
#include <string>
using namespace std;
struct PrescriptionList {
    
    // 1. Dữ liệu thành viên (Member Data)
    PrescriptionItemNode* head;

    // 2. Phương thức thành viên (Member Methods)
    
    // Constructor: Tự động chạy khi 1 đối tượng PrescriptionList được tạo
    PrescriptionList();

    // Destructor: Tự động chạy khi đối tượng bị hủy
    // [RẤT QUAN TRỌNG] để chống rò rỉ bộ nhớ
    ~PrescriptionList();

    // Thêm một thuốc vào ĐẦU danh sách
    void insertAtHead(string maThuoc, int soLuong, string huongDan);

    // Hiển thị tất cả thuốc (cần MedicineManager để tra cứu tên)
    // Lưu ý: Chúng ta sẽ truyền MedicineManager vào khi gọi
    void display(const MedicineManager& medManager); 

    // Hàm nội bộ để dọn dẹp bộ nhớ
    void freeList();
};