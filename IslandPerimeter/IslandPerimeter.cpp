#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool inOnIsland(vector<vector<int> >& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        return (0 <= i && i < m) && (0 <= j && j < n) && (grid[i][j] == 1);
    }

    int cellPerimeter(vector<vector<int> >& grid, int i, int j) {
        int res = 0;
        if(!inOnIsland(grid, i + 1, j))
            res++;
        if(!inOnIsland(grid, i - 1, j))
            res++;
        if(!inOnIsland(grid, i, j + 1))
            res++;
        if(!inOnIsland(grid, i, j - 1))
            res++;
        return res;
    }

    void dfs(vector<vector<int> >& grid, int i, int j, map<int, map<int, int> >& visited, int& res) {
        if(visited[i][j] || !inOnIsland(grid, i, j))
            return;

        res += cellPerimeter(grid, i, j);
        visited[i][j] = true;

        dfs(grid, i + 1, j, visited, res);
        dfs(grid, i - 1, j, visited, res);
        dfs(grid, i, j + 1, visited, res);
        dfs(grid, i, j - 1, visited, res);
    }

    int islandPerimeter(vector<vector<int> >& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;

        int i, j;
        bool foundStart = false;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    foundStart = true;
                    break;
                }
            }
            if(foundStart)
                break;
        }
        int res = 0;
        map<int, map<int, int> > visited;
        dfs(grid, i, j, visited, res);
        return res;
    }
};


int main() {
    int a[4][4] = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
    };

    vector<vector<int> > grid;
    for(int i = 0; i < 4; i++){
        vector<int> row = vector<int>(a[i], a[i] + 4);
        grid.push_back(row);
    }

    Solution solution;
    cout << solution.islandPerimeter(grid) << endl;

    return 0;
}
