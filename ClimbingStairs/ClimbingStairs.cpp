/*
 * time: O(n), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
	int climbStairs(int n){		
		int dp[3];
		dp[0] = 1;
		dp[1] = 1;
		
		for(int i = 2; i <= n; i++)
			dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
			
		return dp[n % 3];
	}
};

int main(){
	Solution solution;
	int res = solution.climbStairs(10);
	cout << res << endl;
	return 0;
}

