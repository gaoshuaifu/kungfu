/*
 * time: O(n!), space: O(1)
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution{
public:
    void permuteUniqueHelper(vector<int>& num, int index, vector<vector<int> >& res){
        if(index == num.size()){
            res.push_back(num);
            return;
        }

        map<int, bool> visited;

        for(int i = index; i < num.size(); i++){
            if(visited.find(num[i]) == visited.end()){
                visited[num[i]] = true;
                swap(num[index], num[i]);
                permuteUniqueHelper(num, index + 1, res);
                swap(num[index], num[i]);
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int>& num){
        vector<vector<int> > res;
        permuteUniqueHelper(num, 0, res);
        return res;
    }
};

class Solution1{
public:
    bool nextPermutation(vector<int>& num){
        int n = num.size();
        int i;
        for(i = n - 1; i >= 1; i--)
            if(num[i] > num[i - 1])
                break;

        if(i <= 0){
            reverse(num.begin(), num.end());
            return false;
        }

        int j;
        for(j = n - 1; j >= i; j--)
            if(num[j] > num[i - 1])
                break;

        swap(num[i - 1], num[j]);
        reverse(num.begin() + i, num.end());
        return true;
    }

    vector<vector<int> > permuteUnique(vector<int>& num){
        vector<vector<int> > res;
        sort(num.begin(), num.end());

        do{
            res.push_back(num);
        }while(nextPermutation(num));

        return res;
    }
};

int main(){
    int a[] = {1, 1, 2, 2, 3, 4};
    vector<int> num = vector<int>(a, a + sizeof(a) / sizeof(a[0]));

    Solution solution;
    vector<vector<int> > res = solution.permuteUnique(num);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    cout << endl;
    return 0;
}
