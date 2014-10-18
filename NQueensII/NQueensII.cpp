#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
    bool reject(vector<int>& sol){
        int n = sol.size();
        for(int i = 0; i < n - 1; i++){
            if(sol[i] == sol[n - 1] || abs(sol[i] - sol[n - 1]) == abs(n - 1 - i))
                return true;
        }
        return false;
    }

    void totalNQueensHelper(int n, vector<int>& sol, int& res){
        if(reject(sol))
            return;

        if(sol.size() == n){
            res++;
            return;
        }

        for(int i = 0; i < n; i++){
            sol.push_back(i);
            totalNQueensHelper(n, sol, res);
            sol.pop_back();
        }
    }

    int totalNQueens(int n){
        int res = 0;
        vector<int> sol;
        totalNQueensHelper(n, sol, res);
        return res;
    }
};

int main(){
    int n = 4;

    Solution solution;
    int res = solution.totalNQueens(4);
    cout << res << endl;

    return 0;
}

