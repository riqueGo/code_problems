package top_k_frequent_words;

import java.util.*;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        // Count word frequencies
        Map<String, Integer> wordCount = new HashMap<>();
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }

        // Min-heap with custom comparator
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>((a, b) -> {
            if (!a.getValue().equals(b.getValue())) {
                return a.getValue() - b.getValue(); // smaller frequency first
            } else {
                return b.getKey().compareTo(a.getKey()); // reverse lex order
            }
        });

        for (Map.Entry<String, Integer> entry : wordCount.entrySet()) {
            pq.offer(entry);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        // Fill from the end to keep correct order without reverse
        String[] ans = new String[k];
        int idx = k - 1;
        while (!pq.isEmpty()) {
            ans[idx--] = pq.poll().getKey();
        }

        return Arrays.asList(ans);
    }
}
