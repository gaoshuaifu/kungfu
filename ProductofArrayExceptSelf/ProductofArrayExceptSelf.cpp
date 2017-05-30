class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // At index i, left is the product of nums[0]...nums[i-1]
        int left = 1;
        for(int i = 1; i < n; i++) {
            left *= nums[i - 1];
            res[i] *= left;
        }

        // At index i, right is the product of nums[i+1]...nums[n-1]
        int right = 1;
        for(int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            res[i] *= right;
        }

        return res;
    }
};
