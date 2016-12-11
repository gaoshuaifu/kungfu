#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


// random number between 1 and n
int rand1toN(int n){
  int upper = RAND_MAX / n * n;
  int r;
  do{
    r = rand();
  } while(r >= upper);
  return r % n + 1;
}

class Solution{
public:
  vector<int> sample(int n, int k){
    vector<int> res;

    for(int i = 1; i <= k; i++){
      res.push_back(i);
    }

    srand(time(NULL));
    for(int i = k + 1; i <= n; i++){
      int r = rand1toN(i);
      if(r <= k)
        res[r - 1] = i;
    }

    return res;
  }
};

int main(){
  Solution solution;
  vector<int> res = solution.sample(100, 10);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
