#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	void combinationSumHelper(vector<int>& candidates, int target, int index, vector<int>& sol, vector<vector<int> >& res){
		if(target == 0){
			res.push_back(sol);
			return;
		}
			
		if(index == candidates.size())
			return;
			
		for(int i = 0; candidates[index] * i <= target; i++){
			for(int j = 0; j < i; j++)
				sol.push_back(candidates[index]);
			
			combinationSumHelper(candidates, target - candidates[index] * i, index + 1, sol, res);
			
			for(int j = 0; j < i; j++)
				sol.pop_back();
		}
	}
	
	vector<vector<int> > combinationSum(vector<int>& candidates, int target){
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > res;
		vector<int> sol;
		combinationSumHelper(candidates, target, 0, sol, res);
		return res;
	}
};

int main(){
	vector<int> candidates;
	candidates.push_back(10);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(5);
	
	
	int target = 10;
	
	Solution solution;
	vector<vector<int> > res = solution.combinationSum(candidates, target);
	
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	
	return 0;
}

