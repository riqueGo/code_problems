/*
Approach:
    - Use a monotonic decreasing stack to store indices of temperatures.
    - Iterate through the list of temperatures:
        * While the current temperature is higher than the temperature at the top index of the stack:
            - Pop the top index and compute the number of days until a warmer temperature (i - idx).
        * Push the current index onto the stack.
    - The stack ensures we only process each index once.

Time Complexity:
    - O(n) → Each index is pushed and popped at most once.
Space Complexity:
    - O(n) → Stack can store up to n indices in the worst case (strictly decreasing temperatures).
*/

#include<vector>
#include<stack>
#include<iostream>

using std::vector;
using std::stack;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), idx;
        stack<int> s;
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            while(!s.empty() && temperatures[s.top()] < temperatures[i]) {
                idx = s.top();
                s.pop();

                ans[idx] = i-idx;
            }

            s.push(i);
        }

        return ans;
    }
};

int main() {
    // Example usage:
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    
    for(int days : result) {
        std::cout << days << " ";
    }
    return 0;
}