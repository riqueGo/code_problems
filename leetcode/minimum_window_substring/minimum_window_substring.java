package minimum_window_substring;

class Solution {
    public String minWindow(String s, String t) {
        int[] letters = new int[128];
        for (char c : t.toCharArray()) {
            letters[c]++;
        }

        int left = 0, right = 0, count = t.length();
        int minLength = Integer.MAX_VALUE, start = 0;

        while (right < s.length()) {
            if (letters[s.charAt(right)]-- > 0) {
                count--;
            }
            right++;

            while (count == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }
                if (letters[s.charAt(left)]++ == 0) {
                    count++;
                }
                left++;
            }
        }

        return minLength == Integer.MAX_VALUE ? "" : s.substring(start, start + minLength);
    }
}