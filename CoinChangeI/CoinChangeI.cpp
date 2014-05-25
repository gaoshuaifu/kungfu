#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
public:
	int minCoins(vector<int>& coins, int cents){
		int n = coins.size();
		sort(coins.begin(), coins.end());
		
		int dp[n][cents + 1];
		for(int j = 0; j <= cents; j++)
			dp[0][j] = j;
		
		for(int i = 0; i < n; i++)
			dp[i][0] = 0;
		
		for(int i = 1; i < n; i++){
			for(int j = 1; j <= cents; j++){
				if(j - coins[i] >= 0)
					dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		
		return dp[n - 1][cents];
	}
};

class Solution1{
public:
	int minCoins(vector<int>& coins, int cents){
		int n = coins.size();
		
		int dp[cents + 1];
		for(int i = 0; i <= cents; i++)
			dp[i] = i;
		
		for(int i = 0; i <= cents; i++)
			for(int j = 0; j < n; j++)
				if(i - coins[j] >= 0)
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		
		return dp[cents];	
	}
	
};

int main(){
	int coinsArray[] = {25, 10, 5, 1};
	vector<int> coins(coinsArray, coinsArray + sizeof(coinsArray) / sizeof(coinsArray[0]));
	
	Solution solution;
	Solution1 solution1;
	for(int i = 0; i <= 100; i++)
		cout << i << "\t" << solution.minCoins(coins, i) << "\t" << solution1.minCoins(coins, i) << "\n";
		
	return 0;	
}

