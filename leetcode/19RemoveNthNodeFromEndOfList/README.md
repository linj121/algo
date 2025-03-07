## Method 1: Count the length

`target = length - (n - 1)`

## Method 2: Fast & Slow Pointers

- move fast pointer to index n - 1
- move fast pointer and slow pointer together, until fast pointer reaches the end of the linked list
- we know `len([slow, fast])` is `n + 1`, so the target to be removed is `slow + 1`
- reorder the list by `slow->next = slow->next->next`, free `slow->next` if you're writing C/C++
