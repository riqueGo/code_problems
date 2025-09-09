#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int current = q.front(); q.pop();
            result.push_back(current);

            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return (result.size() == (size_t)numCourses) ? result : vector<int>{};
    }
};

int main() {
    Solution solution;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;
    vector<int> order = solution.findOrder(numCourses, prerequisites);
    // order should be a valid topological sort, e.g., [0, 1, 2, 3] or [0, 2, 1, 3]
    return 0;
}