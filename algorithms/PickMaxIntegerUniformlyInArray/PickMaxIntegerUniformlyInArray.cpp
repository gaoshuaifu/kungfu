#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

// random number between 1 and n
int rand1toN(int n){
    int upper = RAND_MAX / n * n;
    int r;
    do{
        r = rand();
    } while(r >= upper);
    return r % n + 1;
}

class Solution {
public:
    int pickMaxUniformly(vector<int>& nums) {
        int n = nums.size();
        assert(n > 0);

        int res = 0;
        int maxNum = nums[0];
        int maxCount = 1;

        srand(time(NULL));
        for(int i = 1; i < n; i++) {
            if(nums[i] > maxNum) {
                res = i;
                maxNum = nums[i];
                maxCount = 1;
            }
            else if(nums[i] == maxNum) {
                maxCount++;
                int r = rand1toN(maxCount);
                if(r == 1)
                    res = i;
            }
        }
        return res;
    }
};

int main() {
    int a[] = {-1, 0, 6, 2, 5, 6, 6};
    vector<int> nums = vector<int>(a, a + sizeof(a) / sizeof(a[0]));

    Solution solution;
    cout << solution.pickMaxUniformly(nums) << endl;
    return 0;
}
