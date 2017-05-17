#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void partitionHelper(string& str, int target, int start, vector<int>& sol, vector<vector<int> >& res) {
        if (start == str.size()) {
            if(target == 0)
                res.push_back(sol);
            return;
        }

        for(int end = start; end < str.size(); end++) {
            int value = stoi(str.substr(start, end - start + 1));

            sol.push_back(value);
            partitionHelper(str, target - value, end + 1, sol, res);
            sol.pop_back();

            sol.push_back(-value);
            partitionHelper(str, target + value, end + 1, sol, res);
            sol.pop_back();
        }
    }

    vector<vector<int> > partition(string& str, int target) {
        vector<vector<int> > res;
        vector<int> sol;
        partitionHelper(str, target, 0, sol, res);
        return res;
    }
};

int main(){
    string str = "123456789";
    int target = 100;
    Solution solution;
    vector<vector<int> > res = solution.partition(str, target);
    for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[i].size(); j++) {
        if (res[i][j] >= 0) {
        cout << '+';
        }
        cout << res[i][j];
    }
    cout << "\n";
    }
    return 0;
}
