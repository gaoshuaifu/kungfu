#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int kthLargest(vector<int> nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
        for(int i = 0; i < nums.size(); i++) {
            if(i < k) {
                minHeap.push(nums[i]);
            }
            else {
                if(nums[i] > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> nums;
    for(int i = 0; i < 10; i++)
        nums.push_back(i);

    Solution solution;
    cout << solution.kthLargest(nums, 1) << endl;
    cout << solution.kthLargest(nums, nums.size()) << endl;
    return 0;
}
