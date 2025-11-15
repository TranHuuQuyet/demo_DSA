// HashTable.cpp
#include "HashTable.h"
#include <iostream> // Cần cho hàm remove

// 1. Constructor: Cấp phát bộ nhớ và khởi tạo
HashTable::HashTable(int size) {
    this->tableSize = size;
    // Cấp phát một mảng gồm [size] con trỏ HashNode*
    this->table = new HashNode*[this->tableSize];

    // Khởi tạo TẤT CẢ các "xô" (bucket) là NULL
    for (int i = 0; i < this->tableSize; ++i) {
        this->table[i] = NULL; // Quan trọng
    }
}

// 2. Destructor: Dọn dẹp TOÀN BỘ bộ nhớ
HashTable::~HashTable() {
    // Duyệt qua từng "xô"
    for (int i = 0; i < this->tableSize; ++i) {
        HashNode* current = this->table[i];
        // Xóa toàn bộ Danh sách Liên kết tại "xô" này
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            delete temp; // Xóa từng node
        }
    }
    // Sau khi xóa hết các node, xóa chính mảng "table"
    delete[] this->table;
}

// 3. Hàm Băm: Sửa lỗi
int HashTable::hashFunction(std::string key) const { // Thêm const
    unsigned long hash = 5381; // Dùng thuật toán djb2 tốt hơn
    
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    // Dùng 'unsigned long' để tránh số âm
    return hash % this->tableSize; // Dùng 'tableSize'
}

// 4. Insert: Cài đặt lại đúng
void HashTable::insert(MedicineInfo medicine) {
    // Băm mã thuốc để lấy chỉ số "xô"
    int index = hashFunction(medicine.maThuoc);

    // Duyệt DSLK tại "xô" index để tìm xem thuốc đã tồn tại chưa
    HashNode* current = this->table[index];
    while (current != NULL) {
        // TÌM THẤY -> Cập nhật thông tin và return
        if (current->data.maThuoc == medicine.maThuoc) {
            current->data.tenThuoc = medicine.tenThuoc;
            current->data.donViTinh = medicine.donViTinh; // Sửa lỗi 'medicice'
            current->data.donGia = medicine.donGia;
            return;
        }
        current = current->next;
    }

    // KHÔNG TÌM THẤY -> Thêm node mới vào ĐẦU DSLK
    HashNode* newNode = new HashNode();
    newNode->data = medicine;
    newNode->next = this->table[index]; // Nối vào đầu
    this->table[index] = newNode;       // Cập nhật 'head'
}

// 5. Find: Cài đặt hoàn chỉnh
MedicineInfo* HashTable::find(std::string maThuoc) const { // Thêm const
    int index = hashFunction(maThuoc);

    // Bắt đầu duyệt từ "xô" (bucket)
    HashNode* current = this->table[index];
    while (current != NULL) {
        // Nếu tìm thấy đúng mã thuốc
        if (current->data.maThuoc == maThuoc) {
            // Trả về một con trỏ trỏ tới dữ liệu MedicineInfo
            return &(current->data);
        }
        current = current->next;
    }

    // Duyệt hết mà không tìm thấy
    return NULL;
}

// 6. Remove: Cài đặt hoàn chỉnh
void HashTable::remove(std::string maThuoc) {
    int index = hashFunction(maThuoc);

    HashNode* current = this->table[index];
    HashNode* prev = NULL; // Cần con trỏ 'prev' để nối lại DSLK

    // Duyệt DSLK để tìm node cần xóa
    while (current != NULL && current->data.maThuoc != maThuoc) {
        prev = current;
        current = current->next;
    }

    // Trường hợp 1: Không tìm thấy
    if (current == NULL) {
        std::cout << "Loi: Khong tim thay thuoc " << maThuoc << " de xoa." << std::endl;
        return;
    }

    // Trường hợp 2: Tìm thấy (node cần xóa là 'current')

    // Nếu node cần xóa là đầu danh sách
    if (prev == NULL) {
        this->table[index] = current->next;
    }
    // Nếu node cần xóa nằm ở giữa/cuối
    else {
        prev->next = current->next;
    }

    // Giải phóng bộ nhớ cho node 'current'
    delete current;
}