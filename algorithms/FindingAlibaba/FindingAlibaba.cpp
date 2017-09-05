// jiuzhang.com/qa/31/
// mitbbs.com/article_t1/JobHunting/32978937_0_1.html

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // n: the number of caves
    // strategy: the sequence of inspection
    bool findingAlibaba(int n, vector<int> strategy) {
        int k = strategy.size();
        vector<bool> curr(n, true);
        for(int j = 0; j < n; j++)
            curr[j] = (j != strategy[0]);

        for(int i = 1; i < k; i++) {
            vector<bool> next(n, true);
            bool survive = false;
            for(int j = 0; j < n; j++) {
                next[j] = (j != strategy[i]) && (getResult(curr, j - 1) || getResult(curr, j + 1));
                survive = survive || next[j];
            }
            if(!survive)
                return false;
            curr = next;
        }
        return true;
    }
private:
    bool getResult(vector<bool>& curr, int j) {
        if(j < 0 || j >= curr.size())
            return false;
        return curr[j];
    }
};

int main() {
    int a[] = {1, 2, 3, 1, 2, 3, 4};
    vector<int> strategy = vector<int>(a, a + sizeof(a) / sizeof(a[0]));

    int n = 5;
    Solution solution;
    cout << solution.findingAlibaba(n, strategy) << endl;
    return 0;
}
