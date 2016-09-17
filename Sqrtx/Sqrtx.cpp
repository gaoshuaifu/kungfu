/*
 * time: O(log n), space: O(1)
 */
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

class Solution {
public:
  int sqrt(int y) {
    assert(y >= 0);

    if(y <= 1)
      return y;

    int low = 0;
    int high = y / 2 + 1;
    while(high - low > 1) {
      int mid = low + (high - low) / 2;
      long long square = (long long)mid * mid;

      if(y == square)
        return mid;
      else if(y < square)
        high = mid;
      else
        low = mid;
    }
    return low;
  }
};

class Solution1{
public:
  int sqrt(int y) {
    assert(y >= 0);
    if(y <= 1)
      return y;

    double val = y;
    double last;
    do{
      last = val;
      val = (val + y / val) / 2.0;
    }while(abs(val - last) > 0.000001);

    return val;
  }
};

int main(){
  int y = 2147483647;
  Solution solution;
  int res = solution.sqrt(y);
  cout << res << endl;
  return 0;
}
