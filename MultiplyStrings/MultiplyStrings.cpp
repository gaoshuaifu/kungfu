/*
 * time: O(m * n), space: O(m + n)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution{
public:
  string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    assert(n1 > 0 && n2 > 0);

    if(num1 == "0" || num2 == "0")
      return "0";

    string product(n1 + n2, '0');
    for(int i = n1 - 1; i >= 0; i--){
      int carry = 0;
      for(int j = n2 - 1; j >= 0; j--){
        int sum = carry + (num1[i] - '0') * (num2[j] - '0') + (product[i + j + 1] - '0');
        product[i + j + 1] = sum % 10 + '0';
        carry = sum / 10;
      }
      product[i]= carry + '0';
    }

    int i = 0;
    while(i < n1 + n2 && product[i] == '0')
      i++;

    return product.substr(i, n1 + n2 - i);
  }
};

int main(){
  string num1 = "123";
  string num2 = "456";

  Solution solution;
  string product = solution.multiply(num1, num2);
  cout << product << endl;

  return 0;
}

