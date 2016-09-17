/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<string> anagrams(vector<string>& strs){
    vector<string> res;
    map<string, vector<string> > mapping;
    for(int i = 0; i < strs.size(); i++){
      string key = strs[i];
      sort(key.begin(), key.end());
      mapping[key].push_back(strs[i]);
    }

    for(map<string, vector<string> >::iterator it = mapping.begin(); it != mapping.end(); it++){
      vector<string> v = it->second;
      if(v.size() > 1)
        res.insert(res.end(), v.begin(), v.end());
    }
    return res;
  }
};

int main(){
  vector<string> strs;
  strs.push_back("abc");
  strs.push_back("acb");
  strs.push_back("bac");
  strs.push_back("xyz");
  strs.push_back("xzy");
  strs.push_back("rst");

  Solution solution;
  vector<string> res = solution.anagrams(strs);

  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
}

