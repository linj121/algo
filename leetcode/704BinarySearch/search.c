#include <stdio.h>
#include <string.h>

#define ARRSIZE (3)

void intArr2String(const int* arr, const int arrSize, char* result) {
    sprintf(result, "["); 
    result += 1;
    for (int i = 0; i < arrSize; i++) {
        result += sprintf(result, "%d,", arr[i]);
    }
    sprintf(result - 1, "]");
    strcat(result, "\0");
}

int search(int* nums, int numsSize, int target) {
    return -1;
}

int main() {
    int arr[ARRSIZE][ARRSIZE] = {
        {1,2,3},
        {-1,10,20},
        {0,100,1000}
    };

    for (int i = 0; i < ARRSIZE; i++) {
        int res = search(arr[i], 3, 10);
        char arrInString[256] = {0};
        intArr2String(arr[i], ARRSIZE, arrInString);
        fprintf(stdout, "%s\n", arrInString);
        if (res != -1) {
            printf("Target found: %d\n", res);
        }
    }

    return 0;
}
