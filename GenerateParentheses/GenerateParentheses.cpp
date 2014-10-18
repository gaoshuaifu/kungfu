/*
 * time: O(n^2), space: O(n^2)
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    void generateParenthesisHelper(int left, int right, string sol, vector<string>& res){
        if(left == 0 && right == 0){
            res.push_back(sol);
            return;
        }

        if(left > 0)
            generateParenthesisHelper(left - 1, right, sol + "(", res);

        if(left < right)
            generateParenthesisHelper(left, right - 1, sol + ")", res);
    }

    vector<string> generateParenthesis(int n){
        vector<string> res;
        string sol = "";
        generateParenthesisHelper(n, n, sol, res);
        return res;
    }
};

int main(){
    int n = 4;
    Solution solution;
    vector<string> res = solution.generateParenthesis(n);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}

