/*
 * Time Complexity: O(V + E)
 *   - V is the number of courses, E is the number of prerequisites.
 *   - Each node and edge is visited once in DFS.
 *
 * Space Complexity: O(V + E)
 *   - For the adjacency list and visited array.
 */

#include <vector>

using std::vector;

class Solution {

private:
    vector<int> dependenciesByCourses [2000];
    int visited [2000] = {0};

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(vector<int> course : prerequisites) {
            dependenciesByCourses[course[1]].push_back(course[0]);
        }

        for(int i = 0; i < 2000; i++) {
            if(!dfs(i)) return false;
        }

        return true;
    }

    bool dfs(int currCourse) {
        if(visited[currCourse] == 1) return false;
        else if(visited[currCourse] == 2) return true;

        visited[currCourse] = 1;

        for(int dependent : dependenciesByCourses[currCourse]) {
            if(!dfs(dependent)) return false;
        }

        visited[currCourse] = 2;
        return true;
    }
};