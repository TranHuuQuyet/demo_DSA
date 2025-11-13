// LinkedList.h
#pragma once
#include "structs.h"

// Đây là các hàm thao tác *trên* danh sách có sẵn
// Chúng ta không tạo class, mà truyền `head` vào
namespace PrescriptionList {
    void insertAtHead(PrescriptionItemNode*& head, PrescriptionItemNode* newNode);
    void display(PrescriptionItemNode* head);
    void freeList(PrescriptionItemNode*& head); // [QUAN TRỌNG] để chống rò rỉ bộ nhớ
}