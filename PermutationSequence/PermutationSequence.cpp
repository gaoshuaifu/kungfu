/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution{
public:
  string getPermutation(int n, int k){
    assert(n >= 1 && n <= 9);
    assert(k >= 1);

    vector<int> num;
    for(int i = 0; i < n; i++)
      num.push_back(i + 1);

    vector<int> factorial;
    int f = 1;
    for(int i = 0; i < n; i++){
      f *= (i + 1);
      factorial.push_back(f);
    }

    string res;
    int remain = k - 1;
    for(int i = n - 1; i >= 1; i--){
      int digit = remain / factorial[i - 1] + 1;
      remain = remain % factorial[i - 1];
      res.push_back(num[digit - 1] + '0');
      num.erase(num.begin() + digit - 1);
    }
    res.push_back(num[remain] + '0');
    return res;
  }
};

int main(){
  int n = 4;
  int k = 3;

  Solution solution;
  string res;

  for(int i = 1; i <= 24; i++){
    res = solution.getPermutation(n, i);
    cout << res << endl;
  }

  return 0;
}

