#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

inline int max(const int* arr, const int arrSize) {
    assert(arrSize >= 1);
    int res = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] > res) res = arr[i];
    }
    return res;
}

inline int hoursNeeded(const int* piles, const int pilesSize, int speed) {
    int hours = 0;
    for (int i = 0; i < pilesSize; i++) {
        hours += (int)ceil((double)piles[i] / speed);
    }
    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1, right = max(piles, pilesSize);

    while (left < right) {
        int mid = left + (right - left) / 2;
        bool condition = hoursNeeded(piles, pilesSize, mid) <= h;
        if (condition) right = mid;
        else left = mid + 1;
    }

    return left;
}

int main() {
    int arr[4] = {3,6,7,11};
    fprintf(stdout, "Result: %d\n", minEatingSpeed(arr, 4, 8));  

    return 0;
}
