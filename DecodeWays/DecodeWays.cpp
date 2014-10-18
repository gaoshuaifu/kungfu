/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <string>
using namespace std;

class Solution{
public: 
    int numDecodings(string s){
        int n = s.size();
        if(n == 0 || s[0] == '0')
            return 0;
        
        int dp[3];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            char c1 = s[i - 2];
            char c2 = s[i - 1];
            int sum = 10 * (c1 - '0') + (c2 - '0');
            if(sum == 10 || sum == 20)
                dp[i % 3] = dp[(i - 2) % 3];
            else if(sum % 10 == 0)
                return 0;
            else if((sum >= 11 && sum <= 19) || (sum >= 21 && sum <= 26))
                dp[i % 3] = dp[(i - 2) % 3] + dp[(i - 1) % 3];
            else
                dp[i % 3] = dp[(i - 1) % 3];
        }
        return dp[n % 3];
    }
};

int main(){
    string str = "122628";
    Solution solution;
    int res = solution.numDecodings(str);
    cout << res << endl;
    return 0;
}


