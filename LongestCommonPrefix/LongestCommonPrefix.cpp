/*
 * time: O(n * shortest), space: O(shortest)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        int n = strs.size();
        if(n == 0)
            return "";
        
        int m = strs[0].size();     
        for(int i = 1; i < n; i++){
            if(strs[i].size() < m)
                m = strs[i].size();
        }
        
        string res = "";    
        
        for(int i = 0; i < m ; i++){
            char c = strs[0][i];
            for(int j = 1; j < n; j++){
                if(strs[j][i] != c)
                    return res;
            }
            res.push_back(c);
        }
        return res;
    }
};

int main(){
    vector<string> strs;
    strs.push_back("abc");
    strs.push_back("abd");
    strs.push_back("ab");
    
    Solution solution;
    string res = solution.longestCommonPrefix(strs);
    
    cout << res << endl;
    return 0;
}

