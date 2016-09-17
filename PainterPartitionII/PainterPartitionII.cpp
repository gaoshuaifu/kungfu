/*
 * time: O(nlogw), space: O(1)
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(vector<int>& L, int width){
  int n = L.size();

  int s = 0;
  for(int i = 0; i < n - 1; i++){
    s += L[i];
    cout << L[i];
    if(s <= width && s + L[i + 1]> width){
      cout << '|';
      s = 0;
    }
    else
      cout << ' ';
  }
  cout << L[n - 1] << endl;
}

class Solution{
public:
  int maxArray(vector<int>& L){
    int res = INT_MIN;
    for(int i = 0; i < L.size(); i++)
      res = max(res, L[i]);
    return res;
  }

  int sumArray(vector<int>& L){
    int res = 0;
    for(int i = 0; i < L.size(); i++)
      res += L[i];
    return res;
  }

  int paintersNeeded(vector<int>& L, int window){
    int sum = 0;
    int painters = 0;
    for(int i = 0; i < L.size() - 1; i++){
      sum += L[i];
      if(sum <= window && sum + L[i + 1]> window){
        painters++;
        sum = 0;
      }
    }
    painters++;
    return painters;
  }

  int partition(vector<int>& L, int k){
    int low = maxArray(L);
    int high = sumArray(L);
    while(low < high){
      int mid = (low + high) / 2;
      int painters = paintersNeeded(L, mid);
      if(painters <= k)
        high = mid;
      else
        low = mid + 1;
    }

    return low;
  }
};

int main(){
  int A[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
  vector<int> L(A, A + sizeof(A) / sizeof(A[0]));
  int k = 3;

  Solution solution;
  int width = solution.partition(L, k);
  print(L, width);

  return 0;
}
