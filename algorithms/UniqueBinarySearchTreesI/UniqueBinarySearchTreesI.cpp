/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int numTrees(int n){
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - 1 - j];
        }
        return dp[n];
    }
};

int main(){
    Solution solution;
    for(int i = 0; i < 6; i++){
        cout << i << "=>" << solution.numTrees(i) << endl;
    }
    return 0;
}
