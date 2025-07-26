/*
 * Time Complexity: O(N * R)
 *   - N is the total number of stops across all routes.
 *   - R is the number of routes.
 *   - Each stop and bus route may be visited once in the BFS.
 *
 * Space Complexity: O(N + R)
 *   - For the busByStops map, visited sets, and BFS queue.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>

using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::queue;
using std::pair;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> busByStops;
        for(int i = 0; i < routes.size(); i++) {
            for(int j = 0; j < routes[i].size(); j++) {
                int stop = routes[i][j];
                busByStops[stop].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({source, 0});
        unordered_set<int> visitedBus;
        unordered_set<int> visitedStops;

        while(!q.empty()) {
            int currStop = q.front().first;
            int currDist = q.front().second;

            if(currStop == target) return currDist;

            q.pop();

            visitedStops.insert(currStop);
            for(int bus : busByStops[currStop]) {
                if(visitedBus.find(bus) != visitedBus.end()) continue;

                visitedBus.insert(bus);

                for(int stop : routes[bus]) {
                    if(visitedStops.find(stop) == visitedStops.end()) {
                        q.push({stop, currDist+1});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    // create the following test case: [[0,1,6,16,22,23],[14,15,24,32],[4,10,12,20,24,28,33],[1,10,11,19,27,33],[11,23,25,28],[15,20,21,23,29],[29]]
    vector<vector<int>> routes = {
        {0, 1, 6, 16, 22, 23},
        {14, 15, 24, 32},
        {4, 10, 12, 20, 24, 28, 33},
        {1, 10, 11, 19, 27, 33},
        {11, 23, 25, 28},
        {15, 20, 21, 23, 29},
        {29}
    };
    int source = 4;
    int target = 21;
    Solution solution;
    int result = solution.numBusesToDestination(routes, source, target);
    // Expected output: 2
    std::cout << "Number of buses to destination: " << result << std::endl;
    return 0;
}