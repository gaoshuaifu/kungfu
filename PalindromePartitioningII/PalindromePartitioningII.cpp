#include <iostream>
#include <climits>
using namespace std;

/******************
s = "abbaca"

palin[i][j] is true if s[i..j] is a palindrom

    palin[i][j] = (s[i] == s[j]) && (j - i <= 1 || palin[i + 1][j - 1])

dp[i] is the min cuts of s[i..(n - 1)]

    dp[i] = min(dp[i], dp[j + 1] + 1), if s[i..j] is a palindrom, where i <= j <= n - 1

---------------------
    |a |b |b |a |c |a |
---------------------
a |    |    |    |    |    |    |
---------------------
b |    |    |    |    |    |    |
---------------------
b |    |    |    |    |    |    |
---------------------
a |    |    |    |    |    |    |
---------------------
c |    |    |    |    |    |    |
---------------------
a |    |    |    |    |    |    |
---------------------

*******************/

class Solution{
public:
    int minCut(string s){
        int n = s.size();

        bool palin[n][n];
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                palin[i][j] = false;

        int dp[n + 1];
        for(int i = 0; i <= n; i++)
            dp[i] = n - 1 - i;

        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= i; j--){
                if((s[i] == s[j]) && (j - i <= 1 || palin[i + 1][j - 1])){
                    palin[i][j] = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }

        return dp[0];
    }
};

int main(){
    string s = "abbaca";
    Solution solution;
    int res = solution.minCut(s);
    cout << res << endl;
    return 0;
}
