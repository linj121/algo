#include <vector>
#include <iostream>
#include <format>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
		// Init the widest container
		int left = 0;
		int right = height.size() - 1;		
		int water = 0;

		while (left < right) {
			// Area = the smaller height * width
			int currentArea = ((height[left] < height[right]) ? height[left] : height[right]) * (right - left);
			water = currentArea > water ? currentArea : water;
			
			// Always move the smaller one. Moving the bigger one will definitely NOT give us a larger area!
			if (height[left] < height[right]) left++;
			// It does not matter if we move left or right when height[left] == height[right]
			// because neither [l + 1, r] nor [l, r - 1] container a bigger area!
			else right--;
		}
		
		return water;
    } 

};

int main() {
	Solution sol = Solution();
	std::vector<int> input = {1,8,6,2,5,4,8,3,7};
	int maxA = sol.maxArea(input);
	std::cout << std::format("{}", maxA) << std::endl;
}
