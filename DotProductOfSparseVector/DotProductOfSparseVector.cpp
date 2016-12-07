#include <iostream>
#include <vector>
using namespace std;

struct Element {
  int index;
  double value;
}

class Solution {
  double dotProduct(vector<Element>& a, vector<Element>& b) {
    int n1 = a.size();
    int n2 = b.size();
    double res = 0.0;

    int i = 0;
    int j = 0;
    while(i < n1 && j < n2) {
      if(a[i].index < b[j].index)
        i++;
      else if(a[i].index > b[j].index)
        j++
      else {
        res += a[i].value * b[j].value;
        i++;
        j++;
      }
    }
    return res;
  }
}

int main() {
  return 0;
}
