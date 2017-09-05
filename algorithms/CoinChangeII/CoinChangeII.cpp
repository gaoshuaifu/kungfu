#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
public:
    int changeWays(vector<int>& coins, int cents){
        int n = coins.size();
        sort(coins.begin(), coins.end());

        int dp[n][cents + 1];
        for(int j = 0; j <= cents; j++)
            dp[0][j] = 1;

        for(int i = 0; i < n; i++)
            dp[i][0] = 1;

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= cents; j++){
                if(j - coins[i] >= 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n - 1][cents];
    }
};

int main(){
    int coinsArray[] = {25, 10, 5, 1};
    vector<int> coins(coinsArray, coinsArray + sizeof(coinsArray) / sizeof(coinsArray[0]));

    Solution solution;
    for(int i = 0; i <= 100; i++)
        cout << i << "\t" << solution.changeWays(coins, i) << "\n";

    return 0;
}

