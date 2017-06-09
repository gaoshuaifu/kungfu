class Solution {
public:
    int titleToNumber(string s) {
        reverse(s.begin(), s.end());
        int res = 0;
        int base = 1;
        for(auto c : s) {
           res += (c - 'A' + 1) * base;
           base *= 26;
        }
        return res;
    }
};
