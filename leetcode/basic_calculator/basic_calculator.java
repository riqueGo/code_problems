package basic_calculator;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int calculate(String s) {
        int n = s.length();
        int result = 0;
        int sign = 1;                 // current sign to apply to the next number
        Deque<Integer> signStack = new ArrayDeque<>();
        signStack.push(1);            // global sign

        for (int i = 0; i < n; ) {
            char c = s.charAt(i);

            if (c == ' ') {
                i++; // skip spaces
            } else if (Character.isDigit(c)) {
                int num = 0;
                while (i < n && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                result += sign * num; // apply the current sign
            } else if (c == '+') {
                // next number takes current context sign
                sign = signStack.peek();
                i++;
            } else if (c == '-') {
                // next number will be negative in the current context
                sign = -signStack.peek();
                i++;
            } else if (c == '(') {
                // push current sign context for the sub-expression
                signStack.push(sign);
                i++;
            } else if (c == ')') {
                // pop the sign context
                signStack.pop();
                i++;
            } else {
                // any other char (shouldn't happen for valid input) - skip
                i++;
            }
        }

        return result;
    }
}