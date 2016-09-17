/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    int n = height.size();
    stack<int> stk;

    int left[n];
    for(int i = 0; i < n; i++){
      while(!stk.empty() && height[stk.top()] >= height[i])
        stk.pop();

      if(stk.empty())
        left[i] = i;
      else
        left[i] = i - stk.top() - 1;

      stk.push(i);
    }

    while(!stk.empty())
      stk.pop();

    int right[n];
    for(int i = n - 1; i >= 0; i--){
      while(!stk.empty() && height[stk.top()] >= height[i])
        stk.pop();

      if(stk.empty())
        right[i] = n - 1 - i;
      else
        right[i] = stk.top() - i - 1;

      stk.push(i);
    }

    int maxArea = 0;
    for(int i = 0; i < n; i++){
      int area = height[i] * (left[i] + right[i] + 1);
      maxArea = max(maxArea, area);
    }

    return maxArea;
  }
};

int main(){
  int heightArray[] = {2,1,5,6,2,3};
  vector<int> height = vector<int>(heightArray, heightArray + sizeof(heightArray) / sizeof(heightArray[0]));

  Solution solution;
  cout << solution.largestRectangleArea(height) << endl;

  return 0;
}

