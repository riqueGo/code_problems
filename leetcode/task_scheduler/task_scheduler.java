package task_scheduler;

class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] tasksByQuantity = new int[26];
        int maxQuantity = 0, maxTasks = 0;

        for (char task : tasks) {
            tasksByQuantity[task - 'A']++;
            if (maxQuantity == tasksByQuantity[task - 'A']) {
                maxTasks++;
            } else if (maxQuantity < tasksByQuantity[task - 'A']) {
                maxQuantity = tasksByQuantity[task - 'A'];
                maxTasks = 1;
            }
        }

        int partQuantity = maxQuantity - 1;
        int partLength = n - (maxTasks - 1);
        int emptySlots = partQuantity * partLength;
        int availableTasks = tasks.length - maxQuantity * maxTasks;
        int idles = Math.max(0, emptySlots - availableTasks);

        return tasks.length + idles;
    }
}
