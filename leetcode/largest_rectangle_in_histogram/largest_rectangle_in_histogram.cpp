/*
Approach:
    - Use a monotonic increasing stack to keep track of bars' heights and their starting indices.
    - When a bar is smaller than the top of the stack, pop from stack and calculate the area for the popped height.
    - For each popped height, the width extends from its index to the current index - 1.
    - Finally, process any remaining bars in the stack.

Time Complexity:
    - O(n) → Each bar is pushed and popped at most once.
Space Complexity:
    - O(n) → Stack can store up to n bars in the worst case (increasing heights).
*/

#include<vector>
#include<stack>
#include<algorithm>

using std::vector;
using std::stack;
using std::pair;
using std::max;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];

        int maxArea = 0, height, idx;

        stack<pair<int, int>> s;
        s.push({0, heights[0]});

        for(int i = 1; i < heights.size(); i++) {
            if(s.top().second <= heights[i]) {
                s.push({i, heights[i]});
                continue;
            }

            while(!s.empty() && s.top().second > heights[i]) {
                idx = s.top().first;
                height = s.top().second;
                s.pop();

                maxArea = max(maxArea, height*(i-idx));
            }
            s.push({idx, heights[i]});
        }

        int maxWidth = heights.size();
        while(!s.empty()) {
            idx = s.top().first;
            height = s.top().second;
            s.pop();

            maxArea = max(maxArea, height*(maxWidth-idx));
        }
        return maxArea;
    }
};