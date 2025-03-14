#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * list1 and list2 are both sorted in non-decreasing order.
 * Merge these 2 lists in-place. i.e. don't return a heap malloced data.
 *
**/
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    struct ListNode dummy = {.val=-1, .next=NULL};    
    struct ListNode* temp = &dummy;    
    
    while (list1 && list2) {
        if (list1->val < list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (!list1) temp->next = list2;
    if (!list2) temp->next = list1;

    return dummy.next;
}

int main() {
    


}
