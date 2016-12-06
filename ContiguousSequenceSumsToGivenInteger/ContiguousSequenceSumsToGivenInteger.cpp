#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  bool sumEqual(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0)
      return target == 0;

    int start = 0;
    int end = 0;
    int sum = nums[0];

    while(end < n) {
      if(sum == target)
        return true;
      else if(sum > target && start < end) {
        sum -= nums[start];
        start++;
      }
      else {
        end++;
        sum += nums[end];
      }
    }
    return false;
  }
};

class Solution1 {
public:
  bool sumEqual(vector<int>& nums, int target) {
    int n = nums.size();
    set<int> previousSums;
    previousSums.insert(0);

    int sum = 0;
    for(int i = 0; i < n; i++){
      sum += nums[i];
      if(previousSums.count(sum - target) > 0)
        return true;
      previousSums.insert(sum);
    }
    return false;
  }
};

int main() {
  vector<int> nums;
  nums.push_back(6);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(23);
  int target = 8;

  Solution1 solution;
  cout << solution.sumEqual(nums, target) << endl;
  return 0;
}
