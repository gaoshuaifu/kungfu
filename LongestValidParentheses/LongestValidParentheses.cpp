/*
 * time: O(n), space: O(number of unmatched parentheses)
 */
#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    int longestValidParentheses(string s){
        int n = s.size();
        stack<int> stk;
        stk.push(-1);
        
        for(int i = 0; i < n; i++){
            if(stk.top() < 0){
                stk.push(i);
                continue;   
            }
            if(s[stk.top()] == '(' && s[i] == ')')
                stk.pop();
            else
                stk.push(i);
        }
        
        int maxLen = 0;
        int out = n;
        while(!stk.empty()){
            int in = stk.top();
            int len = out - in - 1;
            maxLen = max(maxLen, len);
            out = in;
            stk.pop();
        }
        return maxLen;
    }
};

int main(){
    string s = ")()())";
    Solution solution;
    int res = solution.longestValidParentheses(s);
    cout << res << endl;
    return 0;
}

