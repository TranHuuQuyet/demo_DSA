// LinkedList.cpp
#include "LinkedList.h"
#include <iostream>

void PrescriptionList::freeList(PrescriptionItemNode*& head) {
    PrescriptionItemNode* current = head;
    while (current != NULL) {
        PrescriptionItemNode* temp = current;
        current = current->next;
        delete temp; // Giải phóng từng node
    }
    head = NULL; // Đặt head về NULL
}

// ... Cài đặt các hàm khác