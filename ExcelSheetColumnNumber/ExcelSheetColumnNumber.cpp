class Solution {
public:
    int titleToNumber(string s) {
        reverse(s.begin(), s.end());
        int res = 0;
        int weight = 1;
        int BASE = 26;
        for(auto c : s) {
           res += (c - 'A' + 1) * weight;
           weight *= BASE;
        }
        return res;
    }
};
