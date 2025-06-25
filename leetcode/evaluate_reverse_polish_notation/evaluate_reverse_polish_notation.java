package evaluate_reverse_polish_notation;

import java.util.Stack;

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> tokensStack = new Stack<>();
        Integer a = 0, b = 0;
        for(String token : tokens) {
            if(!isOperand(token)) {
                tokensStack.push(Integer.parseInt(token));
                continue;
            }

            b = tokensStack.pop();
            a = tokensStack.pop();

            if(token.equals("+")) tokensStack.push(a+b);
            else if(token.equals("-")) tokensStack.push(a-b);
            else if(token.equals("*")) tokensStack.push(a*b);
            else tokensStack.push(a/b);
        }
        return tokensStack.peek();
    }

    boolean isOperand(String op) {
        return op.equals("+") || op.equals("-") || op.equals("*") || op.equals("/");
    }
}