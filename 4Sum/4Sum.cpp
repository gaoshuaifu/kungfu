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
        if(n < 4)
            return res;
            
        map<int, vector<pair<int, int> > > mapping;         
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                mapping[num[i] + num[j]].push_back(make_pair(i, j));
        
        for(map<int, vector<pair<int, int> > >::iterator it = mapping.begin(); it != mapping.end(); it++){
            int sum1 = it->first;
            int sum2 = target - sum1;
            if(sum1 * 2 > target || mapping.find(sum2) == mapping.end())
                continue;
            vector<pair<int, int> > v1 = mapping[sum1];
            vector<pair<int, int> > v2 = mapping[sum2];
            for(int i = 0; i < v1.size(); i++){
                for(int j = 0; j < v2.size(); j++){
                    pair<int, int> pair1 = v1[i];
                    pair<int, int> pair2 = v2[j];
                    if(pair1.first != pair2.first && pair1.second != pair2.second && pair1.first != pair2.second && pair1.second != pair2.first){
                        vector<int> v;
                        v.push_back(num[pair1.first]);
                        v.push_back(num[pair1.second]);
                        v.push_back(num[pair2.first]);
                        v.push_back(num[pair2.second]);
                        sort(v.begin(), v.end());
                        if(find(res.begin(), res.end(), v) == res.end())
                            res.push_back(v);
                    }
                }
            }
        }
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

