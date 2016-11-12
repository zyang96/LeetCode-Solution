/*
Solution 1.
Time complexity: O(1) for all functions
Space complexity: O(n)
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk1;
    stack<int> minStk;
    MinStack() {
    }
    
    void push(int x) {
        stk1.push(x);
        if (minStk.empty()) minStk.push(x);
        else {
            if (x < minStk.top()) minStk.push(x);
            else minStk.push(minStk.top());
        }
    }
    
    void pop() {
        stk1.pop();
        minStk.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
