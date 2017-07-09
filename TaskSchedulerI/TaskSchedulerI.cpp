/*
 We have a list of various types of tasks to perform.
 Task types are identified with an integral identifier:  task of type 1,
 task of type 2, task of type 3, etc. Each task takes 1 time slot to execute,
 and once we have executed a task we need cooldown (parameter) time slots to
 recover before we can execute another task of the same type.

 However, we can execute tasks of other types in the meantime.
 The recovery interval is the same for all task types. We do not reorder
 the tasks: always execute in order in which we received them on input.

 Example 1
  Tasks: 1, 1, 2, 1
  Recovery interval (cooldown): 2
  Output: 7  (order is 1 _ _ 1 2 _ 1)

 Example 2
  Tasks: 1, 2, 3, 1, 2, 3
  Recovery interval (cooldown): 3
  Output: 7  (order is 1 2 3 _ 1 2 3)

 Example 3
  Tasks: 1, 2, 3 ,4, 5, 6, 2, 4, 6, 1, 2, 4
  Recovery interval (cooldown): 6
  Output: 18  (1 2 3 4 5 6 _ _ 2 _ 4 _ 6 1 _ 2 _ 4)
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> schedule(vector<int> tasks, int cooldown) {
        vector<int> res;
        map<int, int> lastIndexMap;
        for(int i = 0; i < tasks.size(); i++) {
            int task = tasks[i];
            if(lastIndexMap.count(task) > 0) {
                int gaps = lastIndexMap[task] + cooldown + 1 - res.size();;
                if(gaps > 0)
                    res.insert(res.end(), gaps, 0);
            }
            res.push_back(task);
            lastIndexMap[task] = res.size() - 1;
        }
        return res;
    }
};

int main() {
    int a[] = {1, 2, 3 ,4, 5, 6, 2, 4, 6, 1, 2, 4};
    vector<int> tasks(a, a + sizeof(a) / sizeof(a[0]));
    int cooldown = 6;

    Solution solution;
    vector<int> res = solution.schedule(tasks, cooldown);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
