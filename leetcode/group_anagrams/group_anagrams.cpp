#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::to_string;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> result;

        for (string& str : strs) {
            // Create a frequency key
            int freq[26] = {0};
            for (char c : str) {
                freq[c - 'a']++;
            }

            // Convert freq array into a unique string key
            string key;
            for (int i = 0; i < 26; i++) {
                key += '#';            // delimiter to avoid ambiguity
                key += to_string(freq[i]);
            }

            umap[key].emplace_back(str);
        }

        for (auto& entry : umap) {
            result.emplace_back(entry.second);
        }

        return result;
    }
};

/*
Time Complexity:
- For each string of length k, counting characters = O(k)
- For n strings: O(n * k)
- Building key from 26 counts = O(26) → O(1)
Total: O(n * k)

Space Complexity:
- Map stores all strings: O(n * k)
- Key size = O(26) per string → O(n)
Overall: O(n * k)
*/


int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution sol;
    sol.groupAnagrams(strs);
}