#include <iostream>
#include <vector>
using namespace std;


/* dp[i][j] = max(coins[i] + min(dp[i+2][j], dp[i+1][j-1]), coins[j] + min(dp[i+1][j-1], dp[i][j-2])) */
class Solution{
public:
  int maxMoney(vector<int>& coins){
    int n = coins.size();
    if(n == 0) return 0;

    int dp[n][n];

    for(int i = 0; i < n; i++)
      dp[i][i] = coins[i];

    for(int i = 0; i < n - 1; i++)
      dp[i][i + 1] = max(coins[i], coins[i + 1]);

    for(int i = n - 3; i >= 0; i--)
      for(int j = i + 2; j < n; j++)
        dp[i][j] = max(coins[i] + min(dp[i+2][j], dp[i+1][j-1]), coins[j] + min(dp[i+1][j-1], dp[i][j-2]));

    return dp[0][n - 1];
  }
};

int main(){
  int coinsArray[] = {3, 2, 2, 3, 1p, 2};
  vector<int> coins(coinsArray, coinsArray + sizeof(coinsArray) / sizeof(coinsArray[0]));

  Solution solution;
  int res = solution.maxMoney(coins);
  cout << res << endl;

  return 0;
}


