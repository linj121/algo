#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int> height) {
        int water = 0;
        std::stack<int> s;

        for (int i = 0; i < (int)height.size(); i++) {
            // If current tower higher than stack top,
            // pop stack pop (because it's smaller)
            // and its trapped water
            while (!s.empty() && height[i] > height[s.top()]) {
                int stacktop = s.top();
                s.pop();

                if (s.empty()) break;

                int water_width = i - s.top() - 1;
                int water_height = std::min(height[s.top()], height[i]) - height[stacktop];
                water += water_width * water_height;
            }

            s.push(i);
        }

        return water;
    }
};

int main() {
    Solution sol = Solution();
    std::vector<int> input = {2,1,0,1,2};
    char charbuffer[128];
    itoa(sol.trap(input), charbuffer, 10);
    std::cout << charbuffer << std::endl;
    return 0;
}