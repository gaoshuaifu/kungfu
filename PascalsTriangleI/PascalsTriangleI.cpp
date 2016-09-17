/*
 * time: O(n^2), space O(n^2)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > generate(int numRows){
    vector<vector<int> > res;
    if(numRows <= 0)
      return res;

    res.push_back(vector<int>(1, 1));
    int i = 2;
    while(i <= numRows){
      vector<int> lastRow = res[i - 2];
      vector<int> currentRow;
      currentRow.push_back(1);
      for(int j = 0; j < lastRow.size() - 1; j++)
        currentRow.push_back(lastRow[j] + lastRow[j + 1]);
      currentRow.push_back(1);
      res.push_back(currentRow);
      i++;
    }

    return res;
  }
};

int main(){
  int numRows = 5;

  Solution solution;
  vector<vector<int> > res = solution.generate(numRows);
  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << " \n";
  }
  cout << endl;

  return 0;
}



