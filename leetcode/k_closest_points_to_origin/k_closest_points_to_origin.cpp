/*
 * Time Complexity: O(N log K)
 *   - N is the number of points, K is the number to return.
 *   - Each insertion and removal from the heap is O(log K).
 *
 * Space Complexity: O(K)
 *   - For the heap storing K points.
 */

#include<vector>
#include<queue>

using std::vector;
using std::priority_queue;

struct Point {
    int x;
    int y;

    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct CompareByDist {
    bool operator()(const Point &a, const Point &b) const {
        int distA = a.x * a.x + a.y * a.y;
        int distB = b.x * b.x + b.y * b.y;
        return distA < distB; 
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, CompareByDist> pq;

        for(vector<int> p : points) {
            pq.emplace(p[0], p[1]);

            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()) {
            Point p = pq.top();
            ans.push_back({p.x,p.y});
            pq.pop();
        }

        return ans;
    }
};