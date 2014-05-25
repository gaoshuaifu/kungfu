#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:	
	void combinationSum2Helper(vector<int>& uniqNum, map<int, int>& mapping, int target, int index, vector<int>& sol, vector<vector<int> >& res){
		if(target == 0){
			res.push_back(sol);
			return;
		}
			
		if(index == uniqNum.size())
			return;
		

		for(int i = 0; uniqNum[index] * i <= target && i <= mapping[uniqNum[index]]; i++){
			for(int j = 0; j < i; j++)
				sol.push_back(uniqNum[index]);
			
			combinationSum2Helper(uniqNum, mapping, target - uniqNum[index] * i, index + 1, sol, res);
			
			for(int j = 0; j < i; j++)
				sol.pop_back();
		}	
	}

	vector<vector<int> > combinationSum2(vector<int> candidates, int target){
        map<int, int> mapping;
        for(int i = 0; i < candidates.size(); i++)
        	mapping[candidates[i]]++;
        
        vector<int> uniqNum;
        for(map<int, int>::iterator it = mapping.begin(); it != mapping.end(); it++)
        	uniqNum.push_back(it->first);
        
		vector<vector<int> > res;
		vector<int> sol;
		combinationSum2Helper(uniqNum, mapping, target, 0, sol, res);
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
	candidates.push_back(1);
	candidates.push_back(5);
	
	
	int target = 8;
	
	Solution solution;
	vector<vector<int> > res = solution.solSum2(candidates, target);
	
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	
	return 0;
}
