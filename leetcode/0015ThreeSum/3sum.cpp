#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int lo = i + 1;
            int hi = nums.size() - 1;

            while (lo < hi) {
                int target = -nums[i];
                if (nums[lo] + nums[hi] == target) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo + 1] == nums[lo]) lo++;
                    lo++;
                } else if (nums[lo] + nums[hi] < target) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        return res;
    }
};

void print2DVec(std::vector<std::vector<int>> twodvec) {
    for (const auto& row : twodvec) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Solution sol = Solution();
    std::vector<int> input = {-1,0,1,2,-1,-4}; 
    auto res = sol.threeSum(input);
    std::vector<std::vector<int>> expected = {{-1,-1,2},{-1,0,1}};
    assert(res == expected);
    print2DVec(res);
}