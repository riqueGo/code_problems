/*
 * Time Complexity: O(NK log(NK))
 *   - N is the number of accounts, K is the maximum number of emails per account.
 *   - Each email is processed, and sorting dominates the complexity.
 *
 * Space Complexity: O(NK)
 *   - For storing parent, size, email mappings, and merged results.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;

struct DisjointSet {
    vector<int> parent, size;
    DisjointSet(int n) : parent(n), size(n, 1) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int node) {
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToIndex;

        // Union accounts by shared emails
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                const string& email = accounts[i][j];
                if(emailToIndex.count(email)) {
                    ds.unionBySize(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }

        // Group emails by their root parent
        vector<vector<string>> mergedEmails(n);
        for(const auto& [email, idx] : emailToIndex) {
            int root = ds.find(idx);
            mergedEmails[root].push_back(email);
        }

        // Build the answer
        vector<vector<string>> ans;
        for(int i = 0; i < n; ++i) {
            if(mergedEmails[i].empty()) continue;
            std::sort(mergedEmails[i].begin(), mergedEmails[i].end());
            vector<string> entry = {accounts[i][0]};
            entry.insert(entry.end(), mergedEmails[i].begin(), mergedEmails[i].end());
            ans.push_back(entry);
        }
        return ans;
    }
};