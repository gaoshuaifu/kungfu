/*
 * time: O(2^n), space: O(1)
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
	void subsetsWithDupHelper(vector<int>& S, int start, vector<int> sol, vector<vector<int> >& res){
		res.push_back(sol);
		map<int, bool> visited;
		for(int i = start; i < S.size(); i++){
			if(visited.find(S[i]) == visited.end()){
				visited[S[i]] = true;
				sol.push_back(S[i]);
				subsetsWithDupHelper(S, i + 1, sol, res);
				sol.pop_back();
			}
		}
	}
	
	vector<vector<int> > subsetsWithDup(vector<int>& S){
		sort(S.begin(), S.end());
		vector<vector<int> > res;
		vector<int> sol;
		subsetsWithDupHelper(S, 0, sol, res);
		return res;
	}
};

class Solution1{
public:
	void subsetsWithDupHelper(vector<int>& S, int index, vector<int> sol, vector<vector<int> >& res){
		res.push_back(sol);
		for(int i = index; i < S.size(); i++){
			if(i == index || S[i] != S[i - 1]){
				sol.push_back(S[i]);
				subsetsWithDupHelper(S, i + 1, sol, res);
				sol.pop_back();
			}
		}
	}
	
	vector<vector<int> > subsetsWithDup(vector<int>& S){
		sort(S.begin(), S.end());
		vector<vector<int> > res;
		vector<int> sol;
		subsetsWithDupHelper(S, 0, sol, res);
		return res;
	}
};

int main(){
	int A[] = {1, 2, 2};
	vector<int> S(A, A + sizeof(A) / sizeof(A[0]));
	
	Solution solution;
	vector<vector<int> > res = solution.subsetsWithDup(S);
	
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	
	return 0;
}

