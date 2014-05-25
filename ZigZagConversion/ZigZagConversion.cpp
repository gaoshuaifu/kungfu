/*
 * time: O(n), space: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	string convert(string text, int nRows){
		if(nRows == 1)
			return text;
		
		vector<vector<char> > buckets(nRows, vector<char>());
		
		int cycle = 2 * nRows - 2;
		for(int i = 0; i < text.size(); i++){
			int a = i % cycle;
			int b;
			if(a >= 0 && a < nRows)
				b = a;
			else
				b = 2 * nRows - 2 - a;
			buckets[b].push_back(text[i]);
		}
		
		string res;
		for(int i = 0; i < buckets.size(); i++){
			for(int j = 0; j < buckets[i].size(); j++)
				res.push_back(buckets[i][j]);
		}
		
		return res;
	}
};

int main(){
	string text = "PAYPALISHIRING";
	int nRows = 3;
	Solution solution;
	string res = solution.convert(text, nRows);
	cout << res << endl;
	return 0;	
}

