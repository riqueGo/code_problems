package longest_palindrome;

class Solution {
    public int longestPalindrome(String s) {
        int[] letters = new int[52];
        for(char ch : s.toCharArray()) {
            if(ch < 'a') {
                letters[ch-'A']++;
            } else {
                letters[ch-'a'+26]++;
            }
        }

        boolean hasOdd = false;
        int total = 0;
        for(int i = 0; i < 52; i++){
            if(letters[i] % 2 == 0) {
                total+=letters[i];
            } else {
                total += letters[i]-1;
                hasOdd = true;
            }
        }

        return hasOdd ? total + 1 : total;
    }
}
