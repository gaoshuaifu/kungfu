#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> multiply(vector<int> A){
    int n = A.size();
    vector<int> res(n, 1);

    int left = 1;
    for(int i = 0; i < n; i++){
      res[i] *= left;
      left *= A[i];
    }

    int right = 1;
    for(int i = n - 1; i >= 0; i--){
      res[i] *= right;
      right *= A[i];
    }

    return res;
  }
};

int main(){
  int a[] = {5, 4, 3, 2, 1};
  vector<int> A(a, a + sizeof(a) / sizeof(a[0]));

  Solution solution;
  vector<int> res = solution.multiply(A);

  cout << res.size() << endl;
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
