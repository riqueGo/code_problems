package longest_substring_without_repeating_characters;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.isEmpty()) return 0;

        int[] table = new int[256];
        int i = 0, j = 0, ans = 0;
        char endChar, startChar = s.charAt(i);
        while(j < s.length()) {
            endChar = s.charAt(j);
            if(table[endChar] == 0) {
                table[endChar]++;
                j++;
                continue;
            }

            ans = Math.max(ans, j-i);

            while(startChar != endChar) {
                table[startChar]--;
                startChar = s.charAt(++i);
            }

            startChar = s.charAt(++i);
            j++;
        }

        ans = Math.max(ans, j-i);
        return ans;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        s.lengthOfLongestSubstring(" ");
    }
}
