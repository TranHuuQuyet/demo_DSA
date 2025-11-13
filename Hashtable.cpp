// HashTable.cpp
#include "HashTable.h"

int HashTable::hashFunction(std::string key) {
    // ... Cài đặt hàm băm (ví dụ: djb2, sdbm)
    // Trả về một chỉ số (index) trong mảng
    return index;
}

MedicineInfo* HashTable::find(std::string maThuoc) {
    int index = hashFunction(maThuoc);
    // 1. Đi đến "xô" (bucket) tại `index`
    // 2. Duyệt qua Danh sách Liên kết tại "xô" đó
    // 3. Nếu tìm thấy `maThuoc` -> return con trỏ
    // 4. Nếu duyệt hết mà không thấy -> return NULL;
}

// ... Cài đặt các hàm khác (insert, remove)