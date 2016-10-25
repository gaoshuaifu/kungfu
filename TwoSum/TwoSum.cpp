/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res(2, -1);
    int n = numbers.size();
    map<int, int> mapping;

    for(int i = 0; i < n; i++){
      if(mapping.find(target - numbers[i]) != mapping.end()){
        res[0] = mapping[target - numbers[i]];
        res[1] = i;
        return res;
      }
      else
        mapping[numbers[i]] = i;
    }
    return res;
  }
};

int main(){
  int numbersArray[] = {2, 7, 5, 11};
  vector<int> numbers(numbersArray, numbersArray + sizeof(numbersArray) / sizeof(numbersArray[0]));
  int target = 9;

  Solution solution;
  vector<int> res = solution.twoSum(numbers, target);
  cout << res[0] << " " << res[1] << endl;

  return 0;
}

