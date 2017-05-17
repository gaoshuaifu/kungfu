class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        while(end < nums.size()) {
            sum += nums[end];
            end++;
            while(sum >= s) {
                minLen = min(minLen, end - start);
                sum -= nums[start];
                start++;
            }
        }
        return minLen == INT_MAX? 0 : minLen;
    }
};
