#include <stack>
#include <algorithm>
#include <iostream>

class MinStack {
public:
    std::stack<int> S;
    std::stack<int> min_history;
    MinStack(): S{}, min_history{} {}
    
    void push(int val) {
       this->S.push(val);
       int current_min = std::min(val, !this->min_history.empty() ? this->min_history.top() : val);
       this->min_history.push(current_min);
    }
 
    void pop() {
       this->S.pop(); 
       this->min_history.pop(); 
    }
    
    int top() {
       return this->S.top(); 
    }
    
    int getMin() {
       return this->min_history.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* minStack = new MinStack();
    std::cout << "Pushing 1" << std::endl;
    minStack->push(1); 
    std::cout << "Pushing 2" << std::endl;
    minStack->push(2); 
    std::cout << "Current min: " << minStack->getMin() << std::endl;
    std::cout << "Pushing 3" << std::endl;
    minStack->push(-1); 
    std::cout << "Current min: " << minStack->getMin() << std::endl;
    std::cout << "Popping" << std::endl;
    minStack->pop();
    std::cout << "Current min: " << minStack->getMin() << std::endl;
}