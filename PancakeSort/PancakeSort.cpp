
// Sort a list using only flip(<list>) and largest_val(<list>) functions
// where flip does a pancake flip
void pancakeSort(vector<int>& nums) {
    int n = nums.size();
    for(int i = n - 1; i > 1; i--) {
        // Find index of max value from a[0..i]
        int maxIndex = findMax(nums, i);

        // Move nums[maxIndex] to nums[i]
        if(maxIndex != i) {
            flip(nums, maxIndex);
            flip(nums, i);
        }
    }
}
