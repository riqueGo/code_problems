/*
Time Complexity:
    - Building the adjacency list (graph): O(n + edges.size()) ≈ O(n)
    - Initializing leaves (degree == 1): O(n)
    - BFS trimming process: Each edge is visited at most twice → O(n)
    - Total: O(n)

Space Complexity:
    - Graph adjacency list: O(n)
    - Degree array: O(n)
    - Queue for leaves: O(n) in the worst case
    - Answer vector: O(2) at worst case
    - Total: O(n)
*/

#include<vector>
#include<unordered_set>
#include<queue>

using std::vector;
using std::unordered_set;
using std::queue;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v); graph[v].push_back(u);
            degree[u]++; degree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) q.push(i);
        }

        int remainLeaves = n, leavesToRemove;
        while(remainLeaves > 2) {
            leavesToRemove = q.size();
            for(int i = 0; i < leavesToRemove; i++) {
                int leaf = q.front(); q.pop();
                for(int neighbor : graph[leaf]) {
                    if(--degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
                
            }
            remainLeaves -= leavesToRemove;
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()); q.pop();
        }

        return ans;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {1,0},
        {1,2},
        {1,3}
    };

    Solution s;
    s.findMinHeightTrees(n, edges);
}