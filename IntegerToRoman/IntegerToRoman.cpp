/*
 * time: O(1), space: O(1)
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string digitToRoman(int digit, char ten, char five, char one){
    string res;

    if(digit == 9){
      res.append(1, one);
      res.append(1, ten);
    }
    else if(digit >= 5){
      res.append(1, five);
      res.append(digit - 5, one);
    }
    else if(digit == 4){
      res.append(1, one);
      res.append(1, five);
    }
    else
      res.append(digit, one);

    return res;
  }

  string intToRoman(int num) {
    string res;
    res += digitToRoman(num / 1000 % 10, '\0', '\0', 'M');
    res += digitToRoman(num / 100 % 10, 'M', 'D', 'C');
    res += digitToRoman(num / 10 % 10, 'C', 'L', 'X');
    res += digitToRoman(num / 1 % 10, 'X', 'V', 'I');
    return res;
  }
};

class Solution1 {
public:
  string intToRoman(int num) {
    const vector<int> nums{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const vector<string> romans{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res;
    int i = 0;
    while (num > 0) {
      while (num >= nums[i]) {
        num -= nums[i];
        res += romans[i];
      }
      i++;
    }
    return res;
  }
};

int main(){
  int num = 3999;

  Solution solution;
  cout << solution.intToRoman(num) << endl;

  return 0;
}
