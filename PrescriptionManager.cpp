// PrescriptionManager.cpp
#include "PrescriptionManager.h"
#include "LinkedList.h" // Cần để gọi chiTietThuoc->insert...
#include <iostream>

// --- Constructor / Destructor ---

// 1. Constructor: Khởi tạo đầu DSLK quản lý
PrescriptionManager::PrescriptionManager() {
    this->head = NULL;
}

// 2. Destructor: Tự động gọi hàm dọn dẹp
PrescriptionManager::~PrescriptionManager() {
    this->freeList();
}

/** * 3. [QUAN TRỌNG] Hàm dọn dẹp bộ nhớ (Private)
 * Đây là mấu chốt của sự ổn định
 */
void PrescriptionManager::freeList() {
    PrescriptionListNode* current = this->head;
    while (current != NULL) {
        PrescriptionListNode* temp = current; // Giữ node quản lý
        current = current->next; // Di chuyển

        // Kích hoạt "Chain Reaction" (Phản ứng dây chuyền):
        // 1. delete data -> gọi ~Prescription()
        // 2. ~Prescription() -> gọi delete chiTietThuoc
        // 3. delete chiTietThuoc -> gọi ~PrescriptionList()
        // 4. ~PrescriptionList() -> gọi freeList() của chính nó
        // 5. Toàn bộ chi tiết thuốc (ItemNode) được dọn sạch
        delete temp->data; // <--- Xóa đối tượng Prescription
        
        delete temp; // <--- Xóa node quản lý (ListNode)
    }
    this->head = NULL;
}

// --- Các hàm nghiệp vụ ---

/**
 * 4. [HÀM CỐT LÕI] Tạo và LƯU TRỮ đơn thuốc mới
 */
void PrescriptionManager::taoDonThuocMoi(std::string maDonThuoc, std::string maBN, MedicineManager& medManager) {
    
    // 1. Kiểm tra xem mã đơn thuốc đã tồn tại chưa
    if (this->timDonThuoc(maDonThuoc) != NULL) {
        std::cout << "Loi: Ma don thuoc " << maDonThuoc << " da ton tai." << std::endl;
        return;
    }

    // 2. Tạo một đối tượng Đơn thuốc mới
    // (Constructor của Prescription sẽ tự 'new PrescriptionList')
    Prescription* donMoi = new Prescription();
    donMoi->maDonThuoc = maDonThuoc;
    donMoi->maBenhNhan = maBN;
    // (Có thể thêm nhập ngày kê đơn ở đây)
    
    std::cout << "--- Bat dau nhap thuoc cho don " << maDonThuoc << " ---" << std::endl;
    std::string maThuoc;
    while (true) {
        std::cout << "Nhap ma thuoc (nhap 'xong' de ket thuc): ";
        std::cin >> maThuoc;
        if (maThuoc == "xong") {
            break;
        }

        // 3. [LOGIC CỦA BẠN - RẤT TỐT] Kiểm tra thuốc
        MedicineInfo* thuoc = medManager.timThuocTheoMa(maThuoc);
        if (thuoc == NULL) {
            // (Hàm timThuocTheoMa của medManager đã tự in lỗi)
            std::cout << "Vui long nhap lai ma thuoc khac." << std::endl;
            continue;
        }

        // 4. Nhập thông tin chi tiết
        int soLuong;
        std::string huongDan;
        std::cout << "  -> Da tim thay: " << thuoc->tenThuoc << std::endl;
        std::cout << "  -> Nhap so luong: ";
        std::cin >> soLuong;
        std::cin.ignore(); // Xóa bộ đệm sau khi nhập số
        std::cout << "  -> Nhap huong dan: ";
        std::getline(std::cin, huongDan);

        // 5. [CÁCH GỌI ĐÚNG] Thêm vào DSLK của đơn thuốc
        donMoi->chiTietThuoc->insertAtHead(maThuoc, soLuong, huongDan);
        std::cout << "  -> Da them thuoc vao don." << std::endl;
    }

    // 6. [QUAN TRỌNG] Lưu đơn thuốc này vào danh sách quản lý
    PrescriptionListNode* newNode = new PrescriptionListNode();
    newNode->data = donMoi;
    newNode->next = this->head; // Thêm vào đầu DSLK
    this->head = newNode;

    std::cout << "--- Da tao va luu don thuoc " << maDonThuoc << " thanh cong! ---" << std::endl;
}

/**
 * 5. Tìm kiếm một đơn thuốc
 */
Prescription* PrescriptionManager::timDonThuoc(std::string maDonThuoc) const {
    PrescriptionListNode* current = this->head;
    while (current != NULL) {
        if (current->data->maDonThuoc == maDonThuoc) {
            return current->data; // Trả về con trỏ Prescription
        }
        current = current->next;
    }
    return NULL; // Không tìm thấy
}

/**
 * 6. Hiển thị chi tiết MỘT đơn thuốc
 */
void PrescriptionManager::hienThiChiTietDonThuoc(const Prescription* donThuoc, const MedicineManager& medManager) const {
    if (donThuoc == NULL) {
        std::cout << "Loi: Don thuoc la NULL." << std::endl;
        return;
    }

    std::cout << "========================================" << std::endl;
    std::cout << "MA DON THUOC: " << donThuoc->maDonThuoc << std::endl;
    std::cout << "BENH NHAN:    " << donThuoc->maBenhNhan << std::endl;
    std::cout << "NGAY KE:      " << donThuoc->ngayKeDon << std::endl;
    std::cout << "--- CHI TIET THUOC ---" << std::endl;
    
    // Ủy quyền việc hiển thị chi tiết cho class PrescriptionList
    donThuoc->chiTietThuoc->display(medManager);
    
    std::cout << "========================================" << std::endl;
}

/**
 * 7. Hiển thị tóm tắt TẤT CẢ đơn thuốc
 */
void PrescriptionManager::hienThiTatCaDonThuoc() const {
    std::cout << "--- DANH SACH TAT CA DON THUOC ---" << std::endl;
    PrescriptionListNode* current = this->head;
    if (current == NULL) {
        std::cout << "(Chua co don thuoc nao)" << std::endl;
        return;
    }
    
    int i = 1;
    while (current != NULL) {
        std::cout << i++ << ". Ma Don: " << current->data->maDonThuoc
                  << ", BN: " << current->data->maBenhNhan << std::endl;
        current = current->next;
    }
}