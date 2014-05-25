/*
 * time: O(n^2), space: O(n)
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
class Solution{
public:
	int maxAreaUnderHistogram(vector<int> heights){
		int n = heights.size();
		if(n == 0)
			return 0;
		
		stack<int> stk;
		int left[n];
		int right[n];
		for(int i = 0; i < n; i++){
			while(!stk.empty() && heights[stk.top()] >= heights[i])
				stk.pop();
				
			if(stk.empty())
				left[i] = i;
			else
				left[i] = i - stk.top() - 1;
			stk.push(i);
		}
		
		while(!stk.empty())
			stk.pop();
			
		for(int i = n - 1; i >= 0; i--){
			while(!stk.empty() && heights[stk.top()] >= heights[i])
				stk.pop();
		
			if(stk.empty())
				right[i] = n - 1 - i;
			else
				right[i] = stk.top() - i - 1;
			stk.push(i);
		}

		int maxArea = 0;
		for(int i = 0; i < n; i++){
			int area = heights[i] * (left[i] + right[i] + 1);
			if(area > maxArea)
				maxArea = area;
		}
		return maxArea;
	}
	
	int maximalRectangle(vector<vector<char> >& matrix){
		int m = matrix.size();
		if(m == 0) return 0;
			
		int n = matrix[0].size();
		if(n == 0) return 0;
			
		vector<int> heights = vector<int>(n, 0);
		int maxArea = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == '0')
					heights[j] = 0;
				else if(matrix[i][j] == '1')
					heights[j]++;
			}
			int area = maxAreaUnderHistogram(heights);
			maxArea = max(maxArea, area);
		}
		return maxArea;
	}
};

int main(){
	char a[3][3] = {{'1', '0', '0'}, {'0', '1', '1'}, {'0', '1', '1'}};
	vector<vector<char> > matrix;
	for(int i = 0; i < 3; i++){
		vector<char> row = vector<char>(a[i], a[i] + 3);
		matrix.push_back(row);
	}
	
	Solution solution;
	int res = solution.maximalRectangle(matrix);
	cout << res << endl;
	
	
	return 0;
}

