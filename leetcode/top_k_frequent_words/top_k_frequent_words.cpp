/*
 * Time Complexity: O(N log K)
 *   - N is the number of unique words.
 *   - Inserting each unique word into the priority queue takes O(log K), 
 *     and there are N unique words.
 *   - Building the frequency map takes O(M), where M is the total number of words.
 *   - Overall: O(M + N log K).
 *
 * Space Complexity: O(N)
 *   - For storing the frequency map and the priority queue.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>

using std::vector;
using std::string;
using std::unordered_map;
using std::priority_queue;
using std::pair;

#define pis pair<int, string>

class myComparator {
  public:
    bool operator() (const pis &p1, const pis &p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordByQuantity;
        for(const string& word : words) {
            wordByQuantity[word]++;
        }

        priority_queue<pis, vector<pis>, myComparator> pq;

        for(const auto& it : wordByQuantity) {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }

        vector<string> ans(k);
        int m = k-1;

        while(pq.size() > 0) {
            ans[m--] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};