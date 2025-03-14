#include <assert.h>
#include <stdio.h>
#define INPUTSIZE (3)

/**
 * It's easy to prove that there must be at least one duplicate in 
 * the array of length n - 1, where each int element takes value from 
 * the range [1, n - 2].
 * O(n) space, O(n) time solution: use a hashset.
 * O(1) space, O(n) time solution: 
 *  - We can vist the nums array by treating it as an array of pointers.
 *    The value of each index represents the index of the next element.
 *    eg. If the value at nums[0] is 2, we jump to nums[2] for the next move.
 *  - By doing so, the array can be viewed as a linked list. It's also guaranteed 
 *    that there's a cycle because there's a duplicate number.
 *    eg. In the following array, the duplicate number is 2, which means we'll visit 
 *        index 2 again after our first visit.
 *        idx: 0 1 2 3 4
 *        val: 1 3 4 2 2
 *                     ^
 *        order: 0 -> 1 -> 3 -> 2 -> 4 -> 2 -> 4 -> 2 -> ...
 *  - Notice that the duplicate number is also the starting node of the loop/cycle.
 *    We can easily find the starting node using the Tortoise and Hare algo, problem solved :)
**/
int findDuplicate(int* nums, int numsSize) {
    int tortoise = 0, hare = 0;
    tortoise = nums[tortoise];
    hare = nums[nums[hare]];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }

    tortoise = 0;
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return tortoise; 
}


int main() {
    typedef struct testcase {
        int* input;
        int inputSize;
        int expected;
    } TestCase;
        
    int inputArr1[5] = {1,3,4,2,2};
    int inputArr2[5] = {3,1,3,4,2};
    int inputArr3[5] = {3,3,3,3,3};
    TestCase testcases[INPUTSIZE] = {
        {.input=inputArr1,.inputSize=(sizeof(inputArr1)/sizeof(int)),.expected=2}, 
        {.input=inputArr2,.inputSize=(sizeof(inputArr2)/sizeof(int)),.expected=3}, 
        {.input=inputArr3,.inputSize=(sizeof(inputArr3)/sizeof(int)),.expected=3}, 
    };

    for (int i = 0; i < INPUTSIZE; i++) {
        printf("Expecting %d\n", testcases[i].expected);
        int res = findDuplicate(testcases[i].input, testcases[i].inputSize);
        assert(res == testcases[i].expected); 
    }

    return 0;
}
