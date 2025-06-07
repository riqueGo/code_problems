package valid_parentheses;

import java.util.Map;
import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        if(s.length() % 2 != 0) return false;

        Map<Character, Character> openByClose = Map.of(
            ')', '(', 
            '}', '{',
            ']', '['
        );

        Stack<Character> bracketsStack = new Stack<>();
        for(Character ch : s.toCharArray()) {
            if(openByClose.containsKey(ch)) {
                if(bracketsStack.empty() || openByClose.get(ch) != bracketsStack.peek()) {
                    return false;
                } else {
                    bracketsStack.pop();
                }
            } else {
                bracketsStack.push(ch);
            }
        }
        return bracketsStack.empty();
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isValid("()[]{}"));
    }
}

