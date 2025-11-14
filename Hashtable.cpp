// HashTable.cpp
#include "HashTable.h"
HashTable::HashTable(int size){
     tableSize = size;
}   
HashTable::~HashTable(){
    
}
void HashTable::insert(MedicineInfo medicine){
    int index = hashFunction(medicine.maThuoc);

    MedicineInfo* current = table[index];
    
    while(current != nullptr){ // cap nhap thuoc vao danh sach
        if(current->maThuoc == medicine.maThuoc){
            current->tenThuoc = medicine.tenThuoc;
            current->donViTinh = medicice.donViTinh;
            current->donGia = medicine.donGia;
            return;
        }
           current = current->next;
    }
    MedicineInfo* newMedi = new MedicineInfo(medicine); // them thuoc neu chua co 
    newMedi->next = table[index];
    table[index] = newMedi;

}
int HashTable::hashFunction(std::string key) {
    int sum = 0;

    for(char c : key){ // Duyệt từng phần tử 
        sum += static_cast<int>(c); // Chuyển sang dãy số ASCII và cộng vào sum 
    }
    retun sum % Hash_table; // trả về phần dư của phép chia tổng cho số phần tử tối đa trong mãng
    
    // ... Cài đặt hàm băm (ví dụ: djb2, sdbm)
    // Trả về một chỉ số (index) trong mảng
}

MedicineInfo* HashTable::find(std::string maThuoc) {
    int index = hashFunction(maThuoc);
    // 1. Đi đến "xô" (bucket) tại `index`
    // 2. Duyệt qua Danh sách Liên kết tại "xô" đó
    // 3. Nếu tìm thấy `maThuoc` -> return con trỏ
    // 4. Nếu duyệt hết mà không thấy -> return NULL;
}

// ... Cài đặt các hàm khác (insert, remove)
