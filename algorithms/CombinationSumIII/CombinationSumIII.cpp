class Solution {
public:
    void combinationSum3Helper(int k, int target, int start, vector<int>& sol, vector<vector<int>>& res) {
        if(sol.size() == k) {
            if(target == 0) {
                res.push_back(sol);
            }
            return;
        }

        for(int i = start; i <= 9; i++) {
            sol.push_back(i);
            combinationSum3Helper(k, target - i, i + 1, sol, res);
            sol.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        combinationSum3Helper(k, target, 1, sol, res);
        return res;
    }
};
