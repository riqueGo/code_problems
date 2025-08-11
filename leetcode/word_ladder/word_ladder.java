package word_ladder;

import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        Set<String> visited = new HashSet<>();

        if (!wordSet.contains(endWord)) return 0;

        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        visited.add(beginWord);

        int count = 0, sizeQ;
        char originalChar;

        while (!queue.isEmpty()) {
            sizeQ = queue.size();
            count++;

            for (int i = 0; i < sizeQ; i++) {
                String curr = queue.poll();
                if (curr.equals(endWord)) return count;

                char[] wordChars = curr.toCharArray();
                for (int j = 0; j < wordChars.length; j++) {
                    originalChar = wordChars[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        wordChars[j] = ch;
                        String changedWord = new String(wordChars);
                        if (wordSet.contains(changedWord) && !visited.contains(changedWord)) {
                            queue.offer(changedWord);
                            visited.add(changedWord);
                        }
                    }
                    wordChars[j] = originalChar;
                }
            }
        }
        return 0;
    }
}
