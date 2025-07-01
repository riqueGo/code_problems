#include <stack>
#include <utility>
#include <algorithm>

using std::stack;
using std::pair;
using std::min;

class MinStack {
private:
    stack<pair<int,int>> s;

public:
    MinStack() {}
    
    void push(int val) {
        if(isEmpty()) s.push({val,val});
        else s.push({val, min(val, getMin())});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }

    bool isEmpty() {
        return s.empty();
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