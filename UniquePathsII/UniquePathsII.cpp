/*
 * time: O(m * n), space: O(min(m, n))
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int> >& grid){
        int m = grid.size();
        if(m == 0) return 0;

        int n = grid[0].size();
        if(n == 0) return 0;

        vector<int> curr(n, 0);
        curr[0] = grid[0][0]? 0 : 1;
        for(int j = 1; j < n; j++)
            curr[j] = grid[0][j]? 0 : curr[j - 1];

        for(int i = 1; i < m; i++){
            vector<int> next(n, 0);
            next[0] = grid[i][0]? 0 : curr[0];
            for(int j = 1; j < n; j++)
                next[j] = grid[i][j]? 0 : next[j - 1] + curr[j];
            curr = next;
        }
        return curr[n - 1];
    }
};

class Solution1{
public:
    int uniquePathsWithObstaclesHigh(vector<vector<int> >& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> curr;
        curr.reserve(n);
        curr[0] = grid[0][0] == 1 ? 0 : 1;
        for(int j = 1; j < n; j++)
            curr[j] = grid[0][j] == 1? 0 : curr[j - 1];

        vector<int> next;
        next.reserve(n);
        for(int i = 1; i < m; i++){
            next[0] = grid[i][0] == 1? 0 : curr[0];
            for(int j = 1; j < n; j++)
                next[j] = grid[i][j] == 1? 0 : curr[j] + next[j - 1];
            swap(curr, next);
        }
        return curr[n - 1];
    }

    int uniquePathsWithObstaclesWide(vector<vector<int> >& grid){
        int m = grid[0].size();
        int n = grid.size();

        vector<int> curr;
        curr.reserve(n);
        curr[0] = grid[0][0] == 1? 0 : 1;
        for(int j = 1; j < n; j++)
            curr[j] = grid[j][0] == 1? 0 : curr[j - 1];
        vector<int> next;
        next.reserve(n);
        for(int i = 1; i < m; i++){
            next[0] = grid[0][i] == 1? 0 : curr[0];
            for(int j = 1; j < n; j++)
                next[j] = grid[j][i] == 1? 0 : curr[j] + next[j - 1];
            swap(curr, next);
        }
        return curr[n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int> >& grid){
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;

        if(m > n)
            return uniquePathsWithObstaclesHigh(grid);
        else
            return uniquePathsWithObstaclesWide(grid);
    }
};

int main(){
    int a[3][4] = {{0,0,0,0},{0,0,1,0},{0,0,0,0}};
    vector<vector<int> > grid;
    for(int i = 0; i < 3; i++){
        vector<int> row = vector<int>(a[i], a[i] + 4);
        grid.push_back(row);
    }
    Solution solution;
    int res = solution.uniquePathsWithObstacles(grid);
    cout << res << endl;

    return 0;
}

