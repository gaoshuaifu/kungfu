/*
 * time: O(2^n), space: O(2^n)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    unsigned int getGrayCode(unsigned int x){
        return (x >> 1) ^ x;    
    }
    
    vector<int> grayCode(int n){
        vector<int> res;
        int m = 1 << n;
        for(unsigned int i = 0; i < m; i++)
            res.push_back(getGrayCode(i));
        return res;
    }
};

int main(){
    int n = 4;
    Solution solution;
    vector<int> res = solution.grayCode(n);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}

