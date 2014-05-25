/*
 * time: O(n!)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void permuteHelper(vector<int> num, int index, vector<vector<int> > &res) {
        if (index == num.size()) {
			res.push_back(num);
			return;
		}
		for (int i = index; i < num.size(); i++) {
			swap(num[index], num[i]);
			permuteHelper(num, index + 1, res);
			swap(num[index], num[i]);
		}
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        permuteHelper(num, 0, res);
        return res;
    }
};


int main(){
	int a[] = {5, 1, 2, 3, 4};
	vector<int> num = vector<int>(a, a + sizeof(a) / sizeof(a[0]));
	
	Solution solution;
	vector<vector<int> > res = solution.permute(num);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	return 0;
}

