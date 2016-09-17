/*
 * time: O(n^2), space: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > threeSum(vector<int>& num){
    vector<vector<int> > res;
    int n = num.size();

    sort(num.begin(), num.end());

    int i = 0;
    while(i < n - 2){
      int first = num[i];
      int j = i + 1;
      int k = n - 1;
      while(j < k){
        int second = num[j];
        int third = num[k];
        int sum = first + second + third;
        if(sum == 0){
          vector<int> sol;
          sol.push_back(first);
          sol.push_back(second);
          sol.push_back(third);
          res.push_back(sol);
          while(j < k && num[j] == second)
            j++;
          while(j < k && num[k] == third)
            k--;
        }
        if(sum < 0)
          while(j < k && num[j] == second)
            j++;
        if(sum > 0)
          while(j < k && num[k] == third)
            k--;
      }
      while(i < n - 2 && num[i] == first)
        i++;
    }
    return res;
  }
};

int main(){
  int a[] = {-1, 0, 1, 2, -1, -4};
  vector<int> num = vector<int>(a, a + sizeof(a) / sizeof(a[0]));

  Solution solution;
  vector<vector<int> > res = solution.threeSum(num);
  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << "\n";
  }
  cout << endl;
  return 0;
}
