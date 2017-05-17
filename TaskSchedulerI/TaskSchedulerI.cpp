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
