/*
Time Complexity:
    - Counting tasks frequencies: O(tasks.size())
    - Iterating over fixed 26 task types: O(26) = O(1)
    - Constant-time arithmetic for parts, slots, and idles
    - Total: O(tasks.size())

Space Complexity:
    - Frequency array tasksByQuantity[26]: O(1)
    - Other variables use O(1) space
    - Total: O(1)
*/

#include<vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tasksByQuantity [26] = {0};
        int maxQuantity = 0, maxTasks = 0;
        for(char task : tasks) {
            tasksByQuantity[task-'A']++;
            if(maxQuantity == tasksByQuantity[task-'A']) maxTasks++;
            else if (maxQuantity < tasksByQuantity[task-'A']) {
                maxQuantity = tasksByQuantity[task-'A'];
                maxTasks = 1;
            }
        }

        int partQuantity = maxQuantity - 1;
        int partLength = n - (maxTasks - 1);
        int emptySlots = partQuantity * partLength;
        int availableTasks = tasks.size() - maxQuantity * maxTasks;
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
};