/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  void nextPermutation(vector<int>& num){
    int n = num.size();

    int i;
    for(i = n - 2; i >= 0; i--){
      if(num[i] < num[i + 1])
        break;
    }

    if(i < 0){
      reverse(num.begin(), num.end());
      return;
    }

    int j;
    for(j = n - 1; j > i; j--){
      if(num[j] > num[i])
        break;
    }

    swap(num[i], num[j]);
    reverse(num.begin() + i + 1, num.end());
  }

  void prevPermutation(vector<int>& num){
    int n = num.size();

    int i;
    for(i = n - 2; i >= 0; i--){
      if(num[i] > num[i + 1])
        break;
    }

    if(i < 0){
      reverse(num.begin(), num.end());
      return;
    }

    int j;
    for(j = n - 1; j > i; j--){
      if(num[j] < num[i])
        break;
    }

    swap(num[i], num[j]);
    reverse(num.begin() + i + 1, num.end());
  }
};


void print(vector<int>& num){
  for(int i = 0; i < num.size(); i++)
    cout << num[i] << " ";
  cout << endl;
}

int main(){
  Solution solution;

  int a[] = {1, 2, 3, 4};
  vector<int> num1 = vector<int>(a, a + sizeof(a) / sizeof(a[0]));
  print(num1);
  for(int i = 0; i < 24; i++){
    solution.nextPermutation(num1);
    print(num1);
  }

  cout << endl;

  int b[] = {4, 3, 2, 1};
  vector<int> num2 = vector<int>(b, b + sizeof(b) / sizeof(b[0]));
  print(num2);
  for(int i = 0; i < 24; i++){
    solution.prevPermutation(num2);
    print(num2);
  }
  return 0;
}
