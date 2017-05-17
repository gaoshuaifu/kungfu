/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping = {
            {'I', 1}, 
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            if(mapping[s[i]] < mapping[s[i + 1]])
                res -= mapping[s[i]];
            else
                res += mapping[s[i]];
        }
        return res;
    }
};

int main(){
    string s = "MMMCMXCIX";

    Solution solution;
    cout << solution.romanToInt(s) << endl;

    return 0;
}
