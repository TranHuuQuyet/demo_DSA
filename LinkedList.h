// LinkedList.h
#pragma once
#include <string>

// --- Forward Declarations ---
struct PrescriptionItemNode; 
struct MedicineInfo; 
class MedicineManager; 
// ---

class PrescriptionList {
private:
    PrescriptionItemNode* head; // [PRIVATE]
    void freeList(); // [PRIVATE]

public:
    PrescriptionList();
    ~PrescriptionList();

    void insertAtHead(std::string maThuoc, int soLuong, std::string huongDan);
    
    // Đã thêm const, không cần const_cast
    void display(const MedicineManager& medManager) const;
};