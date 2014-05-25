/*	
 * time: O(n^2), space O(n)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> getRow(int rowIndex){
		if(rowIndex < 0)
			return vector<int>();

		vector<int> lastRow = vector<int>(1, 1);
		int i = 0;
		while(i < rowIndex){
			vector<int> currentRow;
			currentRow.push_back(1);
			for(int j = 0; j < lastRow.size() - 1; j++)
				currentRow.push_back(lastRow[j] + lastRow[j + 1]);
			currentRow.push_back(1);
			lastRow = currentRow;
			i++;
		}
		return lastRow;
	}
};

int main(){
	int rowIndex = 5;
	
	Solution solution;
	vector<int> res = solution.getRow(rowIndex);
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	
	return 0;
}



