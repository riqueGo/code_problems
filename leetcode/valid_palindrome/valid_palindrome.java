package valid_palindrome;

class Solution {
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length()-1;
        while(left < right) {
            char leftChar = s.charAt(left);
            char rightChar = s.charAt(right);

            if(!isAlphaNumeric(leftChar)) {
                left++;
                continue;
            }

            if(!isAlphaNumeric(rightChar)) {
                right--;
                continue;
            }

            if(isUpperCaseAlpha(leftChar)) leftChar = toLowerCase(leftChar);
            if(isUpperCaseAlpha(rightChar)) rightChar = toLowerCase(rightChar);
            if(leftChar != rightChar) return false;
            
            left++;
            right--;
        }

        return true;
    }

    private boolean isLowerCaseAlpha(char ch) { return ch >= 'a' && ch <= 'z'; }
    private boolean isUpperCaseAlpha(char ch) { return ch >= 'A' && ch <= 'Z'; }
    private boolean isNumeric(char ch) { return ch >= '0' && ch <= '9'; }
    private boolean isAlphaNumeric(char ch) { return isLowerCaseAlpha(ch) || isUpperCaseAlpha(ch) || isNumeric(ch); }
    private char toLowerCase(char ch) { return (char) ('z' - 'Z' + ch); }


    public static void main(String[] args) {
        System.out.println(new Solution().isPalindrome("A man, a plan, a canal: Panama"));
    }
}