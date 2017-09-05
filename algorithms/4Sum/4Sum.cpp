/*
 * time: O(n^2), space: O(n^2)
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution{
public:
    vector<vector<int> > fourSum(vector<int>& num, int target){
        vector<vector<int> > res;
        int n = num.size();
        if(n < 4) {
            return res;
        }

        sort(num.begin(), num.end());
        unordered_multimap<int, pair<int, int>> mapping;
        for(int i = 0; i < num.size(); i++) {
            for(int j = i + 1; j < num.size(); j++) {
                mapping.emplace(num[i] + num[j], make_pair(i, j));
            }
        }

        for(auto i = mapping.begin(); i != mapping.end(); i++) {
            auto a = i->second.first;
            auto b = i->second.second;
            auto range = mapping.equal_range(target - i->first);
            for(auto j = range.first; j != range.second; j++) {
                auto c = j->second.first;
                auto d = j->second.second;
                if (b < c) {
                    res.push_back({num[a], num[b], num[c], num[d]});
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

int main(){
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> num = vector<int>(a, a + sizeof(a) / sizeof(a[0]));
    int target = 0;

    Solution solution;
    vector<vector<int> > res = solution.fourSum(num, target);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    cout << endl;
    return 0;
}
