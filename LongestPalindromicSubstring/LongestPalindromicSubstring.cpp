/*
 * time: O(n^2), space: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        int n = s.size();
        int maxLen = 0;
        int maxStart;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 1; j++){
                int start = i;
                int end = i + j;
                while(start >= 0 && end < n && s[start] == s[end]){
                    start--;
                    end++;
                }
                start++;
                end--;
                int len = end - start + 1;
                if(len > maxLen){
                    maxLen = len;
                    maxStart = start;
                }
            }
        }
        return s.substr(maxStart, maxLen);
    }
};

int main(){
    string s = "abcxycbaww";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
    return 0;
}

