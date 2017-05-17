class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        int i = 0;
        while(i < n) {
            int j = i;
            while(j + 1 < n && nums[j + 1] - nums[j] == 1)
                j++;
            if(i == j) {
                res.push_back(to_string(nums[i]));
            }
            else {
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j + 1;
        }
        return res;
    }
};
