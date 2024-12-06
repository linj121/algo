#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::vector<std::vector<int>> bucket(nums.size() + 1);

        for (const int& n : nums) {
            freq[n]++;
        }
        for (const auto& pair : freq) {
            bucket[pair.second].push_back(pair.first);
        }

        std::vector<int> result;
        for (int i = nums.size(); i > 0; i--) {
            for (const int& n : bucket[i]) {
                result.push_back(n);
                if (result.size() == k) return result;
            }
        }

        return {};
    }
};

int main() {
    Solution sol = Solution();
    std::vector<int> nums = {1,1,1,2,2,3};
    std::vector<int> res = sol.topKFrequent(nums, 2);
    for (const int& n : res) {
        std::cout << std::to_string(n) << std::endl; 
    }
}