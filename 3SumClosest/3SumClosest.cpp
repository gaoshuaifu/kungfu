/*
 * time: O(n^2), space: O(1)
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <climits>
#include <cmath>
using namespace std;

class Solution{
public:
  int threeSumClosest(vector<int>& num, int target){
    int n = num.size();
    assert(n >= 3);

    sort(num.begin(), num.end());

    int minDiff = INT_MAX;
    int closestSum;
    int i = 0;
    while(i < n - 2){
      int first = num[i];
      int j = i + 1;
      int k = n - 1;
      while(j < k){
        int second = num[j];
        int third = num[k];
        int sum = first + second + third;
        int diff = abs(sum - target);
        if(diff == 0)
          return sum;
        if(diff < minDiff){
          minDiff =  diff;
          closestSum = sum;
        }
        if(sum < target)
          while(j < k && num[j] == second)
            j++;
        if(sum > target)
          while(j < k && num[k] == third)
            k--;
      }
      while(i < n - 2 && num[i] == first)
        i++;
    }
    return closestSum;
  }
};

int main(){
  int a[] = {-1, 2, 1, -4};
  vector<int> num = vector<int>(a, a + sizeof(a) / sizeof(a[0]));
  int target = 1;

  Solution solution;
  int closestSum = solution.threeSumClosest(num, target);
  cout << closestSum << endl;
  return 0;
}

