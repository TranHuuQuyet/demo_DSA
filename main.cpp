// main.cpp
#include <iostream>
#include "MedicineManager.h"
#include "PrescriptionManager.h"

int main() {
    // Khởi tạo các hệ thống quản lý
    MedicineManager quanLyKho;
    PrescriptionManager quanLyDon;
    
    // Nạp dữ liệu ban đầu (nếu có)
    quanLyKho.themThuocMoi("P001", "Paracetamol 500mg", ...);
    quanLyKho.themThuocMoi("A025", "Amoxicillin 250mg", ...);

    int choice;
    do {
        // ... Hiển thị menu ...
        // 1. Thêm thuốc vào kho
        // 2. Tạo đơn thuốc mới
        // 3. Hiển thị đơn thuốc
        // ...
        
        switch (choice) {
            case 1:
                // Gọi hàm từ quanLyKho
                break;
            case 2:
                // Gọi hàm từ quanLyDon, truyền `quanLyKho` vào
                quanLyDon.taoDonThuocMoi("BN123", quanLyKho);
                break;
            // ...
        }
    } while (choice != 0);

    return 0;
}