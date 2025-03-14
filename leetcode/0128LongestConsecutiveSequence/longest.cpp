#include <vector>
#include <unordered_set>
#include <cstdio>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numsSet(nums.begin(), nums.end());
        int longest = 0; 
        for (const int& num : nums) {
            if (numsSet.find(num - 1) == numsSet.end()) {
                int nextNum = num + 1;
                int currentLength = 1;
                while (numsSet.find(nextNum) != numsSet.end()) {
                    nextNum++;
                    currentLength++;
                }
                longest = (currentLength > longest) ? currentLength : longest;
            }
        }
        return longest;
    }
};

int main() {
    Solution sol = Solution();
    std::vector<int> vec = {100,4,200,1,3,2};
    int res = sol.longestConsecutive(vec);
    printf("%d\n", res);
}