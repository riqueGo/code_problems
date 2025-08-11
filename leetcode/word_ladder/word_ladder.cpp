/*
 * Time Complexity:
 *   O(L * 26 * N)
 *   - L = length of each word
 *   - N = number of words in wordList
 *   - For each word in the BFS queue, we try changing each of its L positions 
 *     into 26 possible letters, and check membership in an O(1) unordered_set.
 *
 * Space Complexity:
 *   O(N * L)
 *   - wordList stored in an unordered_set → O(N * L)
 *   - visited set storing up to N words
 *   - BFS queue can hold up to N words
 */

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using std::string;
using std::vector;
using std::unordered_set;
using std::queue;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wl(wordList.begin(), wordList.end()), visited;

        if(wl.find(endWord) == wl.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        
        string curr;
        char originalChar;
        int count = 0, sizeQ;

        while(!q.empty()) {
            sizeQ = q.size();
            count++;
            for(int i = 0; i < sizeQ; i++) {
                curr = q.front();
                q.pop();

                if(curr == endWord) return count;

                for(int j = 0; j < curr.size(); j++) {
                    originalChar = curr[j];
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        curr[j] = ch;
                        if(wl.find(curr) != wl.end() && visited.find(curr) == visited.end()) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[j] = originalChar;
                }
            }
        }
        return 0;
    }
};