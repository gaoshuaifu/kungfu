class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        int preMax = nums[0];
        int preMin = nums[0];
        int res = nums[0];
        int currMax;
        int currMin;

        for(int i = 1; i < nums.size(); i++) {
            currMax = max(max(preMax * nums[i], preMin * nums[i]), nums[i]);
            currMin = min(min(preMax * nums[i], preMin * nums[i]), nums[i]);
            res = max(res, currMax);
            preMax = currMax;
            preMin = currMin;
        }
        return res;
    }
};
