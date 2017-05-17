#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isUp = true;
        bool isDown = true;

        for(int i = 1; i < nums.size() && (isUp || isDown); i++) {
            if(nums[i - 1] < nums[i])
                isDown = false;
            else if(nums[i - 1] > nums[i])
                isUp = false;
        }

        return isUp || isDown;
    }
};

int main() {
    return 0;
}
