/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution{
public:
  vector<int> plusOne(vector<int>& digits){
    int i = digits.size() - 1;
    while(digits[i] == 9)
      digits[i--] = 0;
    if(i >= 0)
      digits[i] += 1;
    else
      digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main(){
  int a[] = {9, 9};
  vector<int> digits = vector<int>(a, a + sizeof(a) / sizeof(a[0]));

  Solution solution;
  vector<int> res = solution.plusOne(digits);
  for(int i = 0; i < res.size(); i++)
    cout << res[i];
  cout << endl;
  return 0;
}
