// HashTable.h
#pragma once // đảm bảo file chỉ được include 1 lần
#include "structs.h"// include để  biết các định nghĩa về class/struct 
#include <string> // include thư viện string 

class HashTable {
private:
    // Node NỘI BỘ của Bảng Băm
    struct HashNode {
        MedicineInfo data; // " dữ liệu của 1 đơn thuốc đã được khai báo
        HashNode* next;    // Con trỏ tới node tiếp theo để tránh xung đột
    };

    HashNode** table; // Mảng các con trỏ trỏ tới HashNode
    int tableSize; // khai báo kích thước bảng băm 

    // Hàm băm (private và const)
    int hashFunction(std::string key) const;

public:
    HashTable(int size); //Contructor khởi tạo giá trị
    ~HashTable(); // Destructor xóa giá trị khi chương trình kết thúc

    void insert(MedicineInfo medicine); // khai báo hàm thêm thuốc
    MedicineInfo* find(std::string maThuoc) const; // khai báo hàm tìm thuốc
    void remove(std::string maThuoc); // khai báo hàm xóa thuốc
};