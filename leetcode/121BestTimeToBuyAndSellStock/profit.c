#include <stddef.h>
#include <stdio.h>
#include <assert.h>

size_t
maxProfit(int* prices, const int pricesSize)
{
    int minStock = 0, currentStock = minStock + 1;
    size_t res = 0;

    while (currentStock < pricesSize) {
        if (prices[currentStock] < prices[minStock]) {
            minStock = currentStock;
        } else {
           size_t profit = prices[currentStock] - prices[minStock];
           if (profit > res) res = profit;
        }
        currentStock++;
    }

    return res;
}


int
main(void)
{
    typedef struct {
       int* inputArr;
       size_t inputArrSize;
       size_t expected;
    } TestCase;
    
    int input1[] = {7,1,5,3,6,4};
    int input2[] = {7,6,4,3,1};

    TestCase testcases[2] = {
        {.inputArr = input1, .inputArrSize = 6, .expected = 5},
        {input2, 5, 0}
    };

    for (size_t i = 0; i < sizeof(testcases) / sizeof(testcases[0]); i++) {
        size_t res = maxProfit(testcases[i].inputArr, testcases[i].inputArrSize); 
        // f"Test case: {inputArr} is expecting {expected}, but received {res}"
        assert(res == testcases[i].expected && "This is wrong motherfucker!"); 
    }

}
