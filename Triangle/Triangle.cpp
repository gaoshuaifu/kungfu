/*
 * time: O(n^2), space: O(n)
 */
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


class Solution{
public:
	int minimumTotal(vector<vector<int> >& triangle){ 
		int n = triangle.size();
		
		vector<int> curr(n + 1, 0);
	
		for(int i = n - 1; i >= 0; i--){
			vector<int> next(i + 1, 0);
			for(int j = 0; j < i + 1; j++)
				next[j] = min(curr[j], curr[j + 1]) + triangle[i][j];
			curr = next;
		}

		return curr[0];
	} 
};

class Solution1{
public:
	int minimumTotal(vector<vector<int> >& triangle){ 
		int n = triangle.size();
		for(int i = 0; i < n; i++)
			assert(triangle[i].size() == i + 1);

		vector<int> curr;
		vector<int> next;
		curr.reserve(n);
		next.reserve(n);

		curr[0] = triangle[0][0];
		for(int i = 1; i < n; i++){
			for(int j = 0; j < i + 1; j++){
				if(j == 0)
					next[j] = curr[j] + triangle[i][j];
				else if(j == i)
					next[j] = curr[j - 1] + triangle[i][j];
				else
					next[j] = min(curr[j - 1], curr[j]) + triangle[i][j];
			}
			swap(curr, next);
		}

		int minTotal = curr[0];
		for(int i = 0; i < n; i++){
			if(curr[i] < minTotal)
				minTotal = curr[i];
		}

		return minTotal;
	} 
};

int main(){
	vector<vector<int> > triangle;
	vector<int> row;

	row.clear();
	row.push_back(2);
	triangle.push_back(row);

	row.clear();
	row.push_back(3);
	row.push_back(4);
	triangle.push_back(row);
	
	row.clear();
	row.push_back(6);
	row.push_back(5);
	row.push_back(7);
	triangle.push_back(row);

	row.clear();
	row.push_back(4);
	row.push_back(1);
	row.push_back(8);
	row.push_back(3);
	triangle.push_back(row);

	Solution solution;
	int res = solution.minimumTotal(triangle);
	cout << res << endl;
	return 0;
}

