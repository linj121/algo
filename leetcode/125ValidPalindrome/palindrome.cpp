#include <string>
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string cleanedStr = "";

        for (const char& c : s) {
            if (isalnum(c)) {
                cleanedStr += char(tolower(c));
            }
        }

        int left = 0;
        int right = cleanedStr.length() - 1;

        while (left < right) {
            if (cleanedStr[left] != cleanedStr[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};


int main() {
    Solution sol = Solution();
    std::string input = "A man, a plan, a canal: Panama";
    bool res = sol.isPalindrome(input);
    std::cout << (res ? "True" : "False") << std::endl; 
}