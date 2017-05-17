class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int left = 1;
        for(int i = 1; i < n; i++) {
            left *= nums[i - 1];
            res[i] *= left;
        }

        int right = 1;
        for(int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            res[i] *= right;
        }

        return res;
    }
};


class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        left[0] = 1;
        left[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
            right[n - i - 1] = right[n - i] * nums[n - i];
        }

        vector<int> res;
        res.push_back(right[0]);
        for(int i = 1; i < n - 1; i++) {
            res.push_back(left[i] * right[i]);
        }
        res.push_back(left[n - 1]);
        return res;
    }
};
