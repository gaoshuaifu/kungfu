#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public: 
    int longestCommonSubsequenceLen(string s1, string s2){
        if(s1.size() < s2.size())
            swap(s1, s2);
        
        int m = s1.size();
        int n = s2.size();
        
        vector<int> curr(n + 1, 0);
        for(int j = 0; j <= n; j++)
            curr[j] = 0;
        
        for(int i = 1; i <= m; i++){
            vector<int> next(n + 1, 0);
            next[0] = 0;
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1])
                    next[j] = curr[j - 1] + 1;
                else
                    next[j] = max(curr[j], next[j - 1]);
            }
            curr = next;
        }
        
        return curr[n];
    }
    
    enum Direction{UP, LEFT, UPLEFT};
    
    string longestCommonSubsequence(string s1, string s2){
        if(s1.size() < s2.size())
            swap(s1, s2);
        
        int m = s1.size();
        int n = s2.size();
        
        int len[m + 1][n + 1];
        len[0][0] = 0;
        for(int j = 1; j <= n; j++)
            len[0][j] = 0;
        for(int i = 1; i <= m; i++)
            len[i][0] = 0;
        
        Direction dir[m + 1][n + 1];
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    len[i][j] = len[i - 1][j - 1] + 1;
                    dir[i][j] = UPLEFT;
                }
                else{
                    if(len[i - 1][j] >= len[i][j - 1]){
                        len[i][j] = len[i - 1][j];
                        dir[i][j] = UP;
                    }
                    else{
                        len[i][j] = len[i][j - 1];
                        dir[i][j] = LEFT;
                    }
                }
            }
        }
        
        string res;
        int i = m;
        int j = n;
        while(i >= 1 && j >= 1){
            if(dir[i][j] == UPLEFT){
                res.push_back(s1[i - 1]);
                i--;
                j--;
            }
            else if(dir[i][j] == UP)
                i--;
            else if(dir[i][j] == LEFT)
                j--;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};

int main(){
    string s1 = "abcbdab";
    string s2 = "bdcaba";

    Solution solution;
    int len = solution.longestCommonSubsequenceLen(s1, s2);
    string str = solution.longestCommonSubsequence(s1, s2);
    
    cout << len << "\n";
    cout << str << "\n";
    
    return 0;
}