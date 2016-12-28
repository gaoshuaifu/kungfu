#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int getLeadingOnes(int num) {
    int ones = 0;
    int i = 7;
    while(i >= 0 && ((num >> i) & 1) == 1) {
      ones++;
      i--;
    }
    return ones;
  }

  bool validUtf8(vector<int>& data) {
    int count = 0;
    for(int i = 0; i < data.size(); i++) {
      int num = data[i];
      int ones = getLeadingOnes(num);
      if(count <= 0) {
        if(ones == 1)
          return false;
        count = ones - 1;
      }
      else {
        if(ones != 1)
          return false;
        count--;
      }
    }
    return count <= 0;
  }
};

int main() {
  // 11000101 10000010 00000001
  int d1[] = {197, 130, 1};
  vector<int> data1 = vector<int>(d1, d1 + sizeof(d1) / sizeof(d1[0]));

  // 11101011 10001100 00000100
  int d2[] = {235, 140, 4};
  vector<int> data2 = vector<int>(d2, d2 + sizeof(d2) / sizeof(d2[0]));

  Solution solution;
  cout << solution.validUtf8(data1) << endl;
  cout << solution.validUtf8(data2) << endl;
  return 0;
}
