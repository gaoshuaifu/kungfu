/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxArea(vector<int>& height){
    int n = height.size();
    int maxArea = 0;
    int i = 0;
    int j = n - 1;
    while(i < j){
      int left = height[i];
      int right = height[j];
      int area = min(left, right) * (j - i);
      maxArea = max(maxArea, area);
      if(left == right){
        while(i < j && height[i] <= left)
          i++;
        while(i < j && height[j] <= right)
          j--;
      }
      if(left < right)
        while(i < j && height[i] <= left)
          i++;
      else
        while(i < j && height[j] <= right)
          j--;
    }
    return maxArea;
  }
};

class Solution1{
public:
  int maxArea(vector<int> &height) {
    int n = height.size();
    int maxArea = 0;
    int i = 0;
    int j = n - 1;
    while(i < j){
      int area = min(height[i], height[j]) * (j - i);
      maxArea = max(maxArea, area);
      if(height[i] == height[j]){
        i++;
        j--;
      }
      else if(height[i] < height[j])
        i++;
      else
        j--;
    }
    return maxArea;
  }
};

int main(){
  int heightArr[] = {2, 3, 10, 5, 7, 8, 9};
  vector<int> height(heightArr, heightArr + sizeof(heightArr) / sizeof(heightArr[0]));
  Solution solution;
  int res = solution.maxArea(height);
  cout << res << endl;
  return 0;
}

