package min_stack;

import java.util.Stack;

class Node {
    public int val;
    public int minVal;

    Node(int val, int minVal) {
        this.val = val;
        this.minVal = minVal;
    }
}

class MinStack {
    private Stack<Node> s;

    public MinStack() {
        s = new Stack<>();
    }
    
    public void push(int val) {
        if(isEmpty()) s.push(new Node(val,val));
        else s.push(new Node(val, Math.min(val, getMin())));
    }
    
    public void pop() {
        s.pop();
    }
    
    public int top() {
        return s.peek().val;
    }
    
    public int getMin() {
        return s.peek().minVal;
    }

    public boolean isEmpty() {
        return s.isEmpty();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
