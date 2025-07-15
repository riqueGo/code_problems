package word_break;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    private Set<Integer> positionVisited;
    private String s;
    private List<String> wordDict;

    private boolean fn(int pos) {
        if(pos == s.length()) return true;
        positionVisited.add(pos);

        for(String word : wordDict) {
            int endPos = word.length() + pos;
            if(
                endPos <= s.length() &&
                !positionVisited.contains(endPos) &&
                word.equals(s.substring(pos, endPos)) &&
                fn(endPos)
            ) return true;
        }
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        this.positionVisited = new HashSet<>();
        this.s = s;
        this.wordDict = wordDict;
        return fn(0);
    }
}
