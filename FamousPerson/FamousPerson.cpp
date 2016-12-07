#include <iostream>
using namespace std;

const int N = 4;
bool MATRIX[N][N] = {
  {0, 0, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 1, 0}
};

class Solution {
public:
  int findCelebrity(int n) {
    int i = 0;
    int j = n - 1;
    while(i < j) {
      if(knows(i, j))
        i++;
      else
        j--;
    }

    for(int k = 0; k < n; k++) {
      if(k == i)
        continue;
      if(knows(i, k) || !knows(k, i))
        return -1;
    }
    return i;
  }

private:
  bool knows(int i, int j) {
    return MATRIX[i][j];
  }
};

int main() {
  Solution solution;
  cout << solution.findCelebrity(N) << endl;
  return -1;
}
