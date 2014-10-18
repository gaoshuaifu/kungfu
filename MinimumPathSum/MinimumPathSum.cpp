/*
 * time: O(m * n), space: O(min(m, n))
 */
#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int minPathSum(vector<vector<int> >& grid){
        int m = grid.size();
        if(m == 0) return 0;
            
        int n = grid[0].size();
        if(n == 0) return 0;
        
        vector<int> curr(n, 0);
        curr[0] = grid[0][0];
        for(int j = 1; j < n; j++)
            curr[j] = curr[j - 1] + grid[0][j];
        
        for(int i = 1; i < m; i++){
            vector<int> next(n, 0);
            next[0] = curr[0] + grid[i][0];
            for(int j = 1; j < n; j++)
                next[j] = min(curr[j], next[j - 1]) + grid[i][j];
            curr = next;
        }
        return curr[n - 1];
    }       
};

class Solution1{
public:
    int minPathSumHigher(vector<vector<int> >& grid){
        int m = grid[0].size();
        int n = grid.size();
        
        vector<int> curr(m, 0);
        curr[0] = grid[0][0];
        for(int j = 1; j < m; j++)
            curr[j] = curr[j - 1] + grid[0][j];
            
        for(int i = 1; i < n; i++){
            vector<int> next(m, 0);
            next[0] = curr[0] + grid[i][0];
            for(int j = 1; j < m; j++)
                next[j] = min(next[j - 1], curr[j]) + grid[i][j];
            curr = next;
        }
        return curr[m - 1];
    }
    
    int minPathSumWider(vector<vector<int> >& grid){
        int m = grid[0].size();
        int n = grid.size();    
        
        vector<int> curr(n, 0);
        curr[0] = grid[0][0];
        for(int j = 1; j < n; j++)
            curr[j] = curr[j - 1] + grid[j][0];
            
        for(int i = 1; i < m; i++){
            vector<int> next(n, 0);
            next[0] = curr[0] + grid[0][i];
            for(int j = 1; j < n; j++)
                next[j] = min(next[j - 1], curr[j]) + grid[j][i];
            curr = next;
        }
        return curr[n - 1];
    }
    
    int minPathSum(vector<vector<int> >& grid){
        int m = grid.size();
        if(m == 0) return 0;
            
        int n = grid[0].size();
        if(n == 0) return 0;
            
        if(m <= n)
            return minPathSumWider(grid);
        else
            return minPathSumHigher(grid);
    }       
};

class Solution2{
public:
    int minPathSum(vector<vector<int> >& grid){
        int m = grid.size();
        if(m == 0)
            return 0;
        
        int n = grid[0].size();
        if(n == 0)
            return 0;
        
        int count[m][n];
        count[0][0] = grid[0][0];
        
        for(int i = 1; i < n; i++)
            count[0][i] = count[0][i - 1] + grid[0][i];
            
        for(int i = 1; i < m; i++)
            count[i][0] = count[i - 1][0] + grid[i][0];
            
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                count[i][j] = min(count[i - 1][j], count[i][j - 1]) + grid[i][j];
    
        return count[m - 1][n - 1];
    }   
};

int main(){
    int a[2][3] = {{1, 2, 5}, {3, 2, 1}};
    vector<vector<int> > grid;
    for(int i = 0; i < 2; i++){
        vector<int> row = vector<int>(a[i], a[i] + 3);
        grid.push_back(row);
    }
    
    Solution solution;
    int res = solution.minPathSum(grid);
    cout << res << endl;
    
    return 0;
}

