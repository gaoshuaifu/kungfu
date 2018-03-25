class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(count > 0) {
                if(nums[i] == major) {
                    count++;
                }
                else {
                    count--;
                }
            }
            else {
                major = nums[i];
                count = 1;
            }
        }
        return major;
    }
};
