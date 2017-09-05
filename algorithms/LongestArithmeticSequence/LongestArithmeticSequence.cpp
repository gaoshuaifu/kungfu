#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    int longestArithmeticSequence(vector<int> nums) {
        int n = nums.size();
        if(n <= 2)
            return n;

        vector<map<int, int> > maps(n, map<int, int>());
        int maxLen = 2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int len = maps[j].find(diff) == maps[j].end()? 2 : maps[j][diff] + 1;
                maps[i][diff] = len;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};

int main() {
    int a[] = {1, 3, 9, 100, 5, 7};
    vector<int> nums = vector<int>(a, a + sizeof(a) / sizeof(a[0]));
    Solution solution;
    int res = solution.longestArithmeticSequence(nums);
    cout << res << endl;
    return 0;
}
