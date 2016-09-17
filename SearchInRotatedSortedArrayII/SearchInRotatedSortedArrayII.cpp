/*
 * time: O(n), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
  bool search(int A[], int n, int target){
    int l = 0;
    int h = n - 1;
    for(int i = 0; i < n; i++)
      if(A[i] == target)
        return true;
    return false;
  }
};

int main(){
  int A[] = {4, 5, 6, 7, 0, 1, 2};
  int target = 2;

  Solution solution;
  int res = solution.search(A, sizeof(A)/sizeof(A[0]), target);
  cout << res << endl;

  return 0;
}



