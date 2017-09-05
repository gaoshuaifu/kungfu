/*
 * time: O(m * n), space: O(min(m, n))
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n){
        if(n > m)
            swap(m, n);

        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++)
            curr[j] = 1;

        for(int i = 1; i < m; i++){
            vector<int> next(n, 0);
            next[0] = 1;
            for(int j = 1; j < n; j++)
                next[j] = curr[j] + next[j - 1];
            curr = next;
        }
        return curr[n - 1];
    }
};

int main(){
    int m = 2;
    int n = 2;

    Solution solution;
    int res = solution.uniquePaths(m, n);
    cout << res << endl;

    return 0;
}

