#include <iostream>
using namespace std;

string NUMBERS[] = {
  "", "One", "Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine",
  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
  "Seventeen", "Eighteen", "Nineteen"};

string TENS[] = {
  "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
  "Eighty", "Ninety"};

class Solution {
public:
  string tripletToEnglish(int num) {
    string res;
    if (num >= 100) {
      res += NUMBERS[num / 100];
      res += " Hundred ";
      num %= 100;
    }

    if (num >= 20) {
      res += TENS[num / 10];
      res += " ";
      res += NUMBERS[num % 10];
    }
    else {
      res += NUMBERS[num];
    }
    return res;
  }

  string numberToWords(int num) {
    if(num == 0)
      return "Zero";

    string res;

    if(num < 0) {
      res += "Minus ";
      num *= -1;
    }

    if(num >= 1000 * 1000 * 1000) {
      res += tripletToEnglish(num / (1000 * 1000 * 1000));
      res += " Billion ";
      num %= 1000 * 1000 * 1000;
    }

    if(num >= 1000 * 1000) {
      res += tripletToEnglish(num / (1000 * 1000));
      res += " Million ";
      num %= 1000 * 1000;
    }

    if (num >= 1000) {
      res += tripletToEnglish(num / (1000));
      res += " Thousand ";
      num %= 1000;
    }

    if (num >= 0) {
      res.append(tripletToEnglish(num));
    }

    return res;
  }
};

int main() {
  int num = 482910231;
  Solution solution;
  cout << solution.numberToWords(num) << endl;
  return 0;
}
