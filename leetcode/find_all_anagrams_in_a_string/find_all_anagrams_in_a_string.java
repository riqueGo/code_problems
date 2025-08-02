package find_all_anagrams_in_a_string;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int[] letters = new int[26];
        int maxP = p.length();
        int l = 0, r = 0;

        for (int i = 0; i < maxP; i++) {
            letters[p.charAt(i) - 'a']++;
        }

        List<Integer> ans = new ArrayList<>();

        while (r < s.length()) {
            char currChar = s.charAt(r);
            if (letters[currChar - 'a'] > 0) {
                letters[currChar - 'a']--;
                r++;
                maxP--;

                if (maxP == 0) {
                    ans.add(l);
                    letters[s.charAt(l++) - 'a']++;
                    maxP++;
                }
            } else {
                while (l < r && s.charAt(l) != currChar) {
                    letters[s.charAt(l++) - 'a']++;
                    maxP++;
                }
                l++;
                r++;
            }
        }

        return ans;
    }
}
