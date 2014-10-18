/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        bool hasFound[256] = {false};
        int maxLen = 0;
        int start = 0;
        int end = 0;
        while(end < s.size()){
            if(!hasFound[s[end]]){
                hasFound[s[end]] = true;
                end++;
                continue;
            }

            maxLen = max(maxLen, end - start);
            while(s[start] != s[end]){
                hasFound[s[start]] = false;
                start++;
            }
            start++;
            end++;
        }
        maxLen = max(maxLen, end - start);
        return maxLen;
    }
};

int main(){
    string s = "abcdbxyz";
    Solution solution;
    cout << s << " " << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}

