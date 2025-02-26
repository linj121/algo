#include <stddef.h>
#include <stdbool.h>
#include "linkedList.h"

LinkedList* reverseLinkedList(LinkedList* head) {
    if (!head) {
        return NULL;
    }
    LinkedList* node = NULL;

    while (head != NULL) {
        LinkedList* temp = head->next;
        head->next = node;
        
        node = head;
        head = temp;
    }

    return node;
}

LinkedList* createLinkedListFromArray(int* arr);

char* stringifyLinkedList(LinkedList* head);

bool compareLinkedList(LinkedList* a, LinkedList* b);

int main() {
    

    return 0;
}
