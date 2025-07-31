package letter_combinations_of_a_phone_number;

import java.util.List;
import java.util.Map;
import java.util.ArrayList;

class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return new ArrayList<>();

        Map<Character, List<String>> digitToLetters = Map.of(
            '2', List.of("a", "b", "c"),
            '3', List.of("d", "e", "f"),
            '4', List.of("g", "h", "i"),
            '5', List.of("j", "k", "l"),
            '6', List.of("m", "n", "o"),
            '7', List.of("p", "q", "r", "s"),
            '8', List.of("t", "u", "v"),
            '9', List.of("w", "x", "y", "z")
        );

        List<String> ans = digitToLetters.get(digits.charAt(0));

        for (int i = 1; i < digits.length(); i++) {
            List<String> temp = new ArrayList<>();
            for (String prefix : ans) {
                for (String letter : digitToLetters.get(digits.charAt(i))) {
                    temp.add(prefix + letter);
                }
            }
            ans = temp;
        }

        return ans;
    }
}