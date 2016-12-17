
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int dp[3];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            dp[i % 3] = max(dp[(i - 2) % 3] + nums[i], dp[(i - 1) % 3]);
        }
        return dp[(n - 1) % 3];
    }
};
