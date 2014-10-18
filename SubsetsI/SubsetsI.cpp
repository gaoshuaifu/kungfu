/*
 * time: O(2^n), space: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    void subsetsHelper(vector<int>& S, int start, vector<int> sol, vector<vector<int> >& res){
        res.push_back(sol);
        for(int i = start; i < S.size(); i++){
            sol.push_back(S[i]);
            subsetsHelper(S, i + 1, sol, res);
            sol.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int>& S){
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        vector<int> sol;
        subsetsHelper(S, 0, sol, res);
        return res;
    }
};

int main(){
    int A[] = {1, 2, 3};
    vector<int> S(A, A + sizeof(A) / sizeof(A[0]));

    Solution solution;
    vector<vector<int> > res = solution.subsets(S);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    cout << endl;

    return 0;
}

