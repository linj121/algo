#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    bool isValid(std::string s) {
        std::stack<int> S;

        for (const char& c : s) {
            if (this->mapping.find(c) != this->mapping.end()) {
                if (!S.empty() && S.top() == this->mapping[c]) 
                    S.pop();
                else 
                    return false;
            } else {
                S.push(c);
            }
        }

        return S.empty();
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: validParen <group of parenthesis>" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string inputString = argv[1];
    Solution sol = Solution();
    bool res = sol.isValid(inputString);
    std::cout << (res ? "valid" : "invalid") << std::endl;
}