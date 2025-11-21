    // HashTable.cpp
    #include "Hashtable.h"
    #include <iostream> 

    // 1. Constructor
    HashTable::HashTable(int size) {
        this->tableSize = size;
        this->table = new HashNode*[this->tableSize];
        for (int i = 0; i < this->tableSize; ++i) {
            this->table[i] = NULL;
        }
    }

    // 2. Destructor
    HashTable::~HashTable() {
        for (int i = 0; i < this->tableSize; ++i) {
            HashNode* current = this->table[i];
            while (current != NULL) {
                HashNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] this->table;
    }

    // 3. Hàm Băm
    int HashTable::hashFunction(std::string key) const {
        unsigned long hash = 5381; // djb2
        for (char c : key) {
            hash = ((hash << 5) + hash) + c; // hash * 33 + c
        }
        return hash % this->tableSize;
    }

    // 4. Insert (Tự động Cập nhật nếu đã tồn tại)
    void HashTable::insert(MedicineInfo medicine) {
        int index = hashFunction(medicine.maThuoc);

        HashNode* current = this->table[index];
        while (current != NULL) {
            if (current->data.maThuoc == medicine.maThuoc) {
                current->data = medicine; // Cập nhật
                return;
            }
            current = current->next;
        }

        // Không tìm thấy -> Thêm mới vào đầu
        HashNode* newNode = new HashNode();
        newNode->data = medicine;
        newNode->next = this->table[index];
        this->table[index] = newNode;
    }

    // 5. Find (const)
    MedicineInfo* HashTable::find(std::string maThuoc) const {
        int index = hashFunction(maThuoc);

        HashNode* current = this->table[index];
        while (current != NULL) {
            if (current->data.maThuoc == maThuoc) {
                return &(current->data);
            }
            current = current->next;
        }
        return NULL;
    }

    // 6. Remove
    void HashTable::remove(std::string maThuoc) {
        int index = hashFunction(maThuoc);

        HashNode* current = this->table[index];
        HashNode* prev = NULL;

        while (current != NULL && current->data.maThuoc != maThuoc) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            return; // Không tìm thấy
        }

        if (prev == NULL) {
            this->table[index] = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }
    void HashTable::display() const {
        std::cout << "\n========================================" << std::endl;
        std::cout << "             DANH SACH KHO THUOC          " << std::endl;
        std::cout << "\n========================================" << std::endl;
        std::cout << "Ma thuoc" << std::endl;
        std::cout << "Ten thuoc" << std::endl;
        std::cout << "Don vi tinh" << std::endl;
        std::cout << "Gia Tien" << std::endl;
        std::cout << "========================================" << std::endl;
        for(int i = 0; i < tableSize; i++){
            HashNode* curr = table[i];
            while(curr != nullptr){
                std::cout << curr->data.maThuoc << " | ";
                std::cout << curr->data.tenThuoc << " | ";
                std::cout << curr->data.donViTinh << " | ";
                std::cout << curr->data.donGia << " | " << std::endl;
                curr = curr->next;
            }
     
        }
    }