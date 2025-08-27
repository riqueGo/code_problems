package group_anagrams;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        
        for (String str : strs) {
            // Create frequency array
            int[] freq = new int[26];
            for (char c : str.toCharArray()) {
                freq[c - 'a']++;
            }
            
            // Build key from frequency array
            StringBuilder keyBuilder = new StringBuilder();
            for (int count : freq) {
                keyBuilder.append('#').append(count);
            }
            String key = keyBuilder.toString();
            
            // Add to map
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(str);
        }
        
        return new ArrayList<>(map.values());
    }
}
