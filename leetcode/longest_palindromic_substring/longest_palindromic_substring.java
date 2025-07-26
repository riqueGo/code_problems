package longest_palindromic_substring;

class Solution {
    public String longestPalindrome(String s) {

        int startIdx = 0;
        int longestSize = 0;
        int limit = s.length();

        for (int k = 0; k < limit; k++) {
            for (int i = k, j = k; i >= 0 && j < limit && s.charAt(i) == s.charAt(j); i--, j++) {
                if (j - i > longestSize) {
                    longestSize = j - i;
                    startIdx = i;
                }
            }
            for (int i = k, j = k + 1; i >= 0 && j < limit && s.charAt(i) == s.charAt(j); i--, j++) {
                if (j - i > longestSize) {
                    longestSize = j - i;
                    startIdx = i;
                }
            }
        }
        return s.substring(startIdx, startIdx + longestSize + 1);
    }
}
