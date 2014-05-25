#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution{
public:
	void combineHelper(int n, int k, int start, vector<int>& sol, vector<vector<int> >& res){
		if(sol.size() == k){
			res.push_back(sol);
			return;
		}
		
		for(int i = start; i <= n; i++){
			sol.push_back(i);
			combineHelper(n, k, i + 1, sol, res);
			sol.pop_back();
		}
	}
	
	vector<vector<int> > combine(int n, int k){
		vector<vector<int> > res;
		vector<int> sol;
		combineHelper(n, k, 1, sol, res);
		return res;
	}
};


int main(){
	int n = 4; 
	int k = 2;
	
	Solution solution;
	vector<vector<int> > res = solution.combine(n, k);
	
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	
	return 0;
}

