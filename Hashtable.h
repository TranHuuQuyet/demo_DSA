// HashTable.h
#pragma once
#include "structs.h"
#include <string>

class HashTable {
private:
    // Node NỘI BỘ của Bảng Băm
    struct HashNode {
        MedicineInfo data; // "Gói" dữ liệu MedicineInfo
        HashNode* next;    // Con trỏ tới node tiếp theo
    };

    HashNode** table; // Mảng các con trỏ trỏ tới HashNode
    int tableSize;

    // Hàm băm (private và const)
    int hashFunction(std::string key) const;

public:
    HashTable(int size);
    ~HashTable();

    void insert(MedicineInfo medicine);
    MedicineInfo* find(std::string maThuoc) const; // Thêm const
    void remove(std::string maThuoc);
};