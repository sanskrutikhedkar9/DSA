/*621. Task Scheduler
You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.
​Return the minimum number of intervals required to complete all tasks.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCounts(26, 0); // There are 26 possible tasks (A-Z).
    
    // Count the frequency of each task
    for(char task : tasks) {
        taskCounts[task - 'A']++;
    }
    
    // Sort the task counts in decreasing order
    sort(taskCounts.begin(), taskCounts.end(), greater<int>());
    
    // The maximum frequency
    int maxCount = taskCounts[0];
    
    // Find the number of tasks that have the maximum frequency
    int maxCountTasks = 0;
    for(int count : taskCounts) {
        if(count == maxCount) {
            maxCountTasks++;
        } else {
            break;
        }
    }
    
    // Calculate the length of the ideal task sequence with maximum spacing
    int partitionCount = maxCount - 1;
    int emptySlots = partitionCount * (n - (maxCountTasks - 1));
    int availableTasks = tasks.size() - maxCount * maxCountTasks;
    int idles = max(0, emptySlots - availableTasks);
    
    return tasks.size() + idles;
    }
};