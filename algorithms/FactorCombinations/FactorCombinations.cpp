class Solution {
public:
    void getFactorsHelper(int n, int start, vector<int>& sol, vector<vector<int>>& res) {
        if(n == 1) {
            if(sol.size() > 1) {
                res.push_back(sol);
            }
            return;
        }

        for(int i = start; i <= n; i++) {
            if(n % i == 0) {
                sol.push_back(i);
                getFactorsHelper(n / i, i, sol, res);
                sol.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> sol;
        getFactorsHelper(n, 2, sol, res);
        return res;
    }
};
