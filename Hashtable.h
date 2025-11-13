// HashTable.h
#pragma once
#include "structs.h"

class HashTable {
private:
    // ... Cấu trúc bên trong, ví dụ mảng các con trỏ tới DSLK
    int tableSize;
    // ...
    int hashFunction(std::string key); // Hàm băm

public:
    HashTable(int size); // Constructor
    ~HashTable();        // Destructor (để giải phóng bộ nhớ)

    void insert(MedicineInfo medicine);
    MedicineInfo* find(std::string maThuoc); // Trả về con trỏ, NULL nếu ko thấy
    void remove(std::string maThuoc);
};