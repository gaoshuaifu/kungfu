#include <iostream>
#include <map>
using namespace std;

class Solution{
public:
  enum Type{VOWEL, CONSONANT, NLETTER};

  int lower(char c){
    if(c >= 'A' && c <= 'Z')
      return c - 'A' + 'a';
    else
      return c;
  }

  bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  bool isY(char c){
    return c == 'y';
  }

  bool isConsonant(char c){
    return (c >= 'a' && c <= 'z') && !isVowel(c) && !isY(c);
  }

  bool isNonLetter(char c){
    return (c < 'a' || c > 'z');
  }

  int productSum(string s){
    int n = s.size();
    int sum = 0;
    int product = 1;
    Type last = NLETTER;
    for(int i = 0; i < n; i++){
      char c = lower(s[i]);
      if(isConsonant(c)){
        if(last == VOWEL){
          sum += product;
          product = 1;
        }
        last = CONSONANT;
      }
      else if(isNonLetter(c)){
        if(last == VOWEL){
          sum += product;
          product = 1;
        }
        last = NLETTER;
      }
      else if(isVowel(c)){
        product *= c - 'a' + 1;
        last = VOWEL;
      }
      else if(isY(c)){
        if(last == CONSONANT){
          product *= c - 'a' + 1;
          last = VOWEL;
        }
        else{
          if(last == VOWEL){
            sum += product;
            product = 1;
          }
          last = CONSONANT;
        }
      }
    }

    if(last == VOWEL)
      sum += product;
    return sum;
  }
};

int main(){
  Solution solution;

  cout << solution.productSum("Google Guy") << endl;
  cout << solution.productSum("Yyyyy") << endl;
  cout << solution.productSum("myopia") << endl;
  cout << solution.productSum("Quietly") << endl;
  cout << solution.productSum("I'm Feeling Yucky") << endl;
}
