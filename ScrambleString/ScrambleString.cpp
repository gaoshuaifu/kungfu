/*
 * time: O(n^4), space: O(1)
 */
#include <iostream>
#include <string>
using namespace std;

// dp[i][j][k] is true is s1.sustr(i, k) and s2.substr(j, k) are scramble strings

class Solution{
public:
    bool isScramble(string s1, string s2){
        if(s1.size() != s2.size())
            return false;
            
        int n = s1.size();
        bool dp[n][n][n + 1];
        
        for(int k = 1; k <= n; k++){
            for(int i = 0; i < n - k + 1; i++){
                for(int j = 0; j < n - k + 1; j++){
                    dp[i][j][k] = false;
                    
                    if(s1.substr(i, k) == s2.substr(j, k)){
                        dp[i][j][k] = true;
                        continue;
                    }
                    
                    for(int l = 1; l <= k - 1; l++){
                        if((dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i][j + k - l][l] && dp[i + l][j][k - l])){
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};

class Solution1{
public:
    bool isScrambleHelper(string& s1, int pos1, string& s2, int pos2, int len){
        if(s1.substr(pos1, len) == s2.substr(pos2, len))
            return true;
        
        for(int i = 1; i <= len - 1; i++){
            if(isScrambleHelper(s1, pos1, s2, pos2, i) && isScrambleHelper(s1, pos1 + i, s2, pos2 + i, len - i))
                return true;
                
            if(isScrambleHelper(s1, pos1, s2, pos2 + len - i, i) && isScrambleHelper(s1, pos1 + i, s2, pos2, len - i))
                return true;
        }
        return false;
    }
    
    bool isScramble(string s1, string s2){
        if(s1.size() != s2.size())
            return false;
            
        int n = s1.size();
        return isScrambleHelper(s1, 0, s2, 0, n);
    }
};

int main(){
    string s1 = "great";
    string s2 = "taerg";
    
    Solution solution;
    bool res = solution.isScramble(s1, s2);
    cout << res << endl;
    
    return 0;
}

