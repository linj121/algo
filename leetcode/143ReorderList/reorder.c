#include <stddef.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *dummy = NULL;
    while (head != NULL) {
        struct ListNode *temp = head->next;
        head->next = dummy;

        dummy = head;
        head = temp;
    }
    return dummy;
}

void reorderList(struct ListNode *head) {
    // find the midpoint
    struct ListNode *fast = head->next, *mid = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        mid = mid->next;
    }
    // reverse the second half
    struct ListNode *second = reverseList(mid->next);
    mid->next = NULL;

    // merge the two
    struct ListNode *first = head;
    while (first != NULL && second != NULL) {
        struct ListNode *firstNextTmp = first->next, *secondNextTmp = second->next;
        first->next = second;
        second->next = firstNextTmp;

        first = firstNextTmp;
        second = secondNextTmp;
    }
}

int main(void) {
    return 0;
}
