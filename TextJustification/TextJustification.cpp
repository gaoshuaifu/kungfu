/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<string> fullJustify(vector<string>& words, int L){
    vector<string> res;
    int n = words.size();
    int start = 0;
    int end;
    while(start < n){
      int len = words[start].size();
      end = start + 1;
      while(end < n && len + 1 + words[end].size() <= L){
        len += 1 + words[end].size();
        end++;
      }

      int numWords = end - start;
      int numGaps = numWords - 1;
      int numSpaces = L - (len - numGaps);
      string line = "";
      if(numWords == 1 || end == n){
        for(int i = start; i < end; i++){
          line.append(words[i]);
          if(i < end - 1)
            line.push_back(' ');
        }
        line.append(L - line.size(), ' ');
      }
      else{
        int gapLen = numSpaces / numGaps;
        int numWiderGap = numSpaces % numGaps;

        for(int i = start; i < end; i++){
          line.append(words[i]);
          if(i < end - 1)
            line.append(gapLen, ' ');
          if(i - start < numWiderGap)
            line.push_back(' ');
        }
      }
      res.push_back(line);
      start = end;
    }
    return res;
  }
};



int main(){
  vector<string> words;
  words.push_back("This");
  words.push_back("is");
  words.push_back("an");
  words.push_back("example");
  words.push_back("of");
  words.push_back("text");
  words.push_back("justification.");

  int L = 16;

  Solution solution;
  vector<string> res = solution.fullJustify(words, L);

  for(int i = 0; i < res.size(); i++)
    cout << res[i] << endl;

  return 0;
}

