/*
 * time: O(logn)
 */

#include <iostream>
using namespace std;

class Solution{
public:
  double pow(double x, int n){
    if(n == 0)
      return 1;

    if(x == 0)
      return 0;

    if(x == 1)
      return 1;

    if(x == -1)
      return n % 2? -1 : 1;

    if(n < 0)
      return 1.0 / pow(x, -n);

    double half = pow(x, n / 2);
    if(n % 2)
      return x * half * half;
    else
      return half * half;
  }
};


int main(){
  double x = 0;
  int n = 8;

  Solution solution;
  double res = solution.pow(x, n);
  cout << res << endl;
  return 0;
}

