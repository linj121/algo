#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNodeT;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNodeT* dummy = (ListNodeT*)malloc(sizeof(ListNodeT));
    if (dummy == NULL) { perror("malloc for ListNodeT failed"); return NULL; }
    *dummy = (ListNodeT){.val=-1, .next=NULL};
    ListNodeT* current = dummy;
    bool carry = false;
    
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + (carry ? 1 : 0);
        ListNodeT* tmp = (ListNodeT*)malloc(sizeof(ListNodeT));
        if (tmp == NULL) { perror("malloc for ListNodeT failed"); return NULL; }
        *tmp = (ListNodeT){.val=(sum % 10), .next=NULL};
        current->next = tmp;
        carry = sum > 9;

        current = current->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy->next;
}

int main() {
    return 0;
}
