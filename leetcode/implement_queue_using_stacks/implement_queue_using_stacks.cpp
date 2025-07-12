/*
 * Time Complexity:
 *   - push: O(1)
 *   - pop, peek: Amortized O(1)
 *
 * Space Complexity: O(N)
 *   - N is the number of elements in the queue.
 */

#include<stack>

using std::stack;

class MyQueue {
private:
    stack<int> in;
    stack<int> out;

public:
    MyQueue() {}
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int p = peek();
        out.pop();
        return p;
    }
    
    int peek() {
        if(!out.empty()){
            return out.top();
        }

        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */