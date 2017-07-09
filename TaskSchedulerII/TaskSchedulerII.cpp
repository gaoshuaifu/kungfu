/*
 Write a function that takes as input a list of tasks to run,
 and the recovery interval, and returns an optimal ordering to run the tasks.

 Example 1
  Tasks: 1, 1, 1
  Recovery interval: 2
  The optimal output in this case is "1__1__1".

 Example 2
  Tasks: 1, 1, 1, 2, 2, 2, 3, 3, 3
  Recovery interval: 2
  An optimal ordering is "1 2 3 1 2 3 1 2 3".

 Example 3
  Tasks: 1, 2, 3, 4, 4, 4, 4
  Recovery interval: 1
  An optimal ordering is "4 1 4 2 4 3 4"

 Example 4
  Tasks: 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1
  Recovery interval: 1
  An optimal ordering is "3 2 3 2 3 1 3 2 1 3 2 1"
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TaskCount {
    int task;
    int count;
    TaskCount(int task, int count) {
        this->task = task;
        this->count = count;
    }
};

struct Smaller{
    bool operator() (const TaskCount& a, const TaskCount& b) {
        return a.count < b.count;
    }
};

class Solution {
public:
    vector<int> schedule(vector<int> tasks, int cooldown) {
        vector<int> res;
        map<int, int> counter;
        priority_queue<TaskCount, vector<TaskCount>, Smaller> maxHeap;

        for(int i = 0; i < tasks.size(); i++) {
            counter[tasks[i]]++;
        }

        for(map<int, int>::iterator it = counter.begin(); it != counter.end(); it++)
            maxHeap.push(TaskCount(it->first, it->second));

        while(!maxHeap.empty()) {
            queue<TaskCount> tmpQ;
            for(int i = 0 ; i < cooldown + 1; i++) {
                if(!maxHeap.empty()) {
                    TaskCount taskCount = maxHeap.top();
                    maxHeap.pop();
                    res.push_back(taskCount.task);
                    taskCount.count--;
                    if(taskCount.count > 0)
                        tmpQ.push(taskCount);
                }
                else {
                    if(tmpQ.empty())
                        break;
                    res.push_back(0);
                }
            }
            while(!tmpQ.empty()) {
                maxHeap.push(tmpQ.front());
                tmpQ.pop();
            }
        }
        return res;
    }
};

int main() {
    int a[] = {3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1};
    vector<int> tasks(a, a + sizeof(a) / sizeof(a[0]));
    int cooldown = 2;

    Solution solution;
    vector<int> res = solution.schedule(tasks, cooldown);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
