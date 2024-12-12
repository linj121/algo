#include <string>
#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> prnStack;

        for (const std::string& token : tokens) {
            if (token == "+") {
                int secondArg = prnStack.top(); prnStack.pop();
                int firstArg = prnStack.top(); prnStack.pop();
                prnStack.push(firstArg + secondArg);
            } else if (token == "-") {
                int secondArg = prnStack.top(); prnStack.pop();
                int firstArg = prnStack.top(); prnStack.pop();
                prnStack.push(firstArg - secondArg);
            } else if (token == "/") {
                int secondArg = prnStack.top(); prnStack.pop();
                int firstArg = prnStack.top(); prnStack.pop();
                prnStack.push(firstArg / secondArg);
            } else if (token == "*") {
                int secondArg = prnStack.top(); prnStack.pop();
                int firstArg = prnStack.top(); prnStack.pop();
                prnStack.push(firstArg * secondArg);
            } else {
                prnStack.push(std::stoi(token));
            }
        }

        return prnStack.top();
    }
};

int main() {
    Solution sol = Solution();
    std::vector<std::string> input = {"2","1","+","3","*"};
    int res = sol.evalRPN(input);
    std::cout << res << std::endl;
}