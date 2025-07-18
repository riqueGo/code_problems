package atoi;

class Solution {
    public int myAtoi(String s) {
        if(s.isEmpty()) return 0;

        int i = 0;

        while(i < s.length() && s.charAt(i) == ' ') i++;

        boolean isNegative = false;

        if(i < s.length() && (s.charAt(i) == '-' || s.charAt(i) == '+')) {
            isNegative = s.charAt(i) == '-';
            i++;
        }

        while(i < s.length() && s.charAt(i) == '0') i++;

        String ansStr = "";
        int count = 0;
        while(i < s.length() && count < 11 && '0' <= s.charAt(i) && s.charAt(i) <= '9') {
            ansStr += s.charAt(i++);
            count++;
        }

        if(ansStr.isEmpty()) return 0;

        try {
            int ans = isNegative ? Integer.valueOf("-" + ansStr) : Integer.valueOf(ansStr);
            return ans;
        } catch (Exception e) {
            return isNegative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }
    }
}