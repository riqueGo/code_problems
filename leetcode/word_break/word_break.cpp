/*
 * Time Complexity: O(N^3)
 *   - N is the length of the string s.
 *   - For each position, we try every word and substring comparison.
 *   - Memoization reduces redundant calls, but worst case is cubic due to substring and set operations.
 *
 * Space Complexity: O(N)
 *   - For the positionVisited set and recursion stack.
 */

#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

class Solution {
private:
    bool fn(const string& s, const vector<string>& wordDict, unordered_set<int>& positionVisited, int pos) {
        if(pos == s.size()) return true;
        positionVisited.insert(pos);

        int endPos;
        for(string word : wordDict) {
            endPos = word.size() + pos;
            if(
                endPos <= s.size() &&
                positionVisited.find(endPos) == positionVisited.end() &&
                word == s.substr(pos,endPos-pos) &&
                fn(s, wordDict, positionVisited, endPos)
            ) return true;
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<int> positionVisited;
        return fn(s, wordDict, positionVisited, 0);
    }
};