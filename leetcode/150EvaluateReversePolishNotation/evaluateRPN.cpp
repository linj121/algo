#include <string>
#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> rpnStack;

        for (const std::string& token : tokens) {
            if (token == "+") {
                int secondArg = rpnStack.top(); rpnStack.pop();
                int firstArg = rpnStack.top(); rpnStack.pop();
                rpnStack.push(firstArg + secondArg);
            } else if (token == "-") {
                int secondArg = rpnStack.top(); rpnStack.pop();
                int firstArg = rpnStack.top(); rpnStack.pop();
                rpnStack.push(firstArg - secondArg);
            } else if (token == "/") {
                int secondArg = rpnStack.top(); rpnStack.pop();
                int firstArg = rpnStack.top(); rpnStack.pop();
                rpnStack.push(firstArg / secondArg);
            } else if (token == "*") {
                int secondArg = rpnStack.top(); rpnStack.pop();
                int firstArg = rpnStack.top(); rpnStack.pop();
                rpnStack.push(firstArg * secondArg);
            } else {
                rpnStack.push(std::stoi(token));
            }
        }

        return rpnStack.top();
    }
};

int main() {
    Solution sol = Solution();
    std::vector<std::string> input = {"2","1","+","3","*"};
    int res = sol.evalRPN(input);
    std::cout << res << std::endl;
}