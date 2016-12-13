// www.geeksforgeeks.org/median-of-stream-of-integers-running-integers

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Greater{
  bool operator() (const int a, const int b) {
    return a > b;
  }
};

struct Smaller{
  bool operator() (const int a, const int b) {
    return a < b;
  }
};

class Solution {
public:
  Solution() {
    left.push(INT_MIN);
    right.push(INT_MAX);
  }

  void insert(int num) {
    if(left.size() > right.size()) {
      if(num < left.top()) {
        right.push(left.top());
        left.pop();
        left.push(num);
      } else {
        right.push(num);
      }
    }
    else if(left.size() < right.size()) {
      if(num > right.top()) {
        left.push(right.top());
        right.pop();
        right.push(num);
      } else {
        left.push(num);
      }
    }
    else { // left.size() == right.size()
      if(num < left.top()) {
        left.push(num);
      } else {
        right.push(num);
      }
    }
  }

  float getMedian() {
    if(left.size() > right.size()) {
      return left.top();
    }
    else if(left.size() < right.size()) {
      return right.top();
    }
    else { // left.size() == right.size()
      return (left.top() + right.top()) / 2.0;
    }
  }

private:
  // A max heap containing smaller numbers
  priority_queue<int, vector<int>, Smaller> left;

  // A min heap containing larger numbers
  priority_queue<int, vector<int>, Greater> right;
};

int main() {
  Solution solution;
  int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for(int i = 0; i < 10; i ++) {
    solution.insert(nums[i]);
    cout << solution.getMedian() << endl;
  }
  return 0;
}
