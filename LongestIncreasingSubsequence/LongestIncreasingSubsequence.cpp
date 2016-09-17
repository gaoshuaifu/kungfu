#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* http://en.wikipedia.org/wiki/Longest_increasing_subsequence */
class Solution{
public:
  int binarySearch(vector<int>& num, vector<int>& M, int target){
    int low = 0;
    int high = M.size() - 1;

    while(low <= high){
      int mid = low + (high - low) / 2;
      if(target < num[M[mid]])
        high = mid - 1;
      else if(target >= num[M[mid]])
        low = mid + 1;
    }
    return high;
  }

  int longestIncreasingSubsequenceLen(vector<int> num){
    int n = num.size();
    vector<int> M;
    for(int i = 0; i < n; i++){
      int j = binarySearch(num, M, num[i]);
      if(j == M.size() - 1)
        M.push_back(i);
      else if(num[i] < num[M[j + 1]])
        M[j + 1] = i;
    }

    return M.size();
  }

  vector<int> longestIncreasingSubsequence(vector<int> num){
    int n = num.size();
    vector<int> M;
    vector<int> P;
    for(int i = 0; i < n; i++){
      int j = binarySearch(num, M, num[i]);
      if(i == 0)
        P.push_back(-1);
      else
        P.push_back(M[j]);

      if(j == M.size() - 1)
        M.push_back(i);
      else if(num[i] < num[M[j + 1]])
        M[j + 1] = i;
    }
    vector<int> res;
    int curr = M.back();
    while(curr >= 0){
      res.push_back(num[curr]);
      curr = P[curr];
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

class Solution1{
public:
  int longestIncreasingSubsequenceLen(vector<int> num){
    int n = num.size();
    vector<int> num1 = num;
    vector<int> num2 = num;
    sort(num2.begin(), num2.end());

    vector<int> curr(n + 1, 0);
    for(int j = 0; j <= n; j++)
      curr[j] = 0;

    for(int i = 1; i <= n; i++){
      vector<int> next(n + 1, 0);
      next[0] = 0;
      for(int j = 1; j <= n; j++){
        if(num1[i - 1] == num2[j - 1])
          next[j] = curr[j - 1] + 1;
        else
          next[j] = max(curr[j], next[j - 1]);
      }
      curr = next;
    }

    return curr[n];
  }

  enum Direction{UP, LEFT, UPLEFT};

  vector<int> longestIncreasingSubsequence(vector<int> num){
    int n = num.size();
    vector<int> num1 = num;
    vector<int> num2 = num;
    sort(num2.begin(), num2.end());

    int len[n + 1][n + 1];
    len[0][0] = 0;
    for(int j = 1; j <= n; j++)
      len[0][j] = 0;
    for(int i = 1; i <= n; i++)
      len[i][0] = 0;

    Direction dir[n + 1][n + 1];

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(num1[i - 1] == num2[j - 1]){
          len[i][j] = len[i - 1][j - 1] + 1;
          dir[i][j] = UPLEFT;
        }
        else{
          if(len[i - 1][j] >= len[i][j - 1]){
            len[i][j] = len[i - 1][j];
            dir[i][j] = UP;
          }
          else{
            len[i][j] = len[i][j - 1];
            dir[i][j] = LEFT;
          }
        }
      }
    }

    vector<int> res;
    int i = n;
    int j = n;
    while(i >= 1 && j >= 1){
      if(dir[i][j] == UPLEFT){
        res.push_back(num1[i - 1]);
        i--;
        j--;
      }
      else if(dir[i][j] == UP)
        i--;
      else if(dir[i][j] == LEFT)
        j--;
    }
    reverse(res.begin(), res.end());

    return res;
  }
};

int main(){
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  vector<int> num(arr, arr + sizeof(arr) / sizeof(arr[0]));

  Solution solution;
  int len = solution.longestIncreasingSubsequenceLen(num);
  cout << len << "\n";

  vector<int> seq = solution.longestIncreasingSubsequence(num);
  for(int i = 0; i < seq.size(); i++)
    cout << seq[i] << " ";
  cout << "\n";

  return 0;
}
