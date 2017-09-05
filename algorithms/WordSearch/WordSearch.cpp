/*
 * time: O(m * n), space: O(m * n)
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

class Solution{
public:
    bool isInBound(vector<vector<char> >& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }

    bool dfs(vector<vector<char> >& board, map<int, map<int, bool> >& visited, int i, int j, string& word, int k){
        if(!isInBound(board, i, j) || visited[i][j])
            return false;

        if(board[i][j] != word[k])
            return false;

        if(k == word.size() - 1)
            return true;

        visited[i][j] = true;

        if(dfs(board, visited, i, j + 1, word, k + 1))
            return true;

        if(dfs(board, visited, i, j - 1, word, k + 1))
            return true;

        if(dfs(board, visited, i + 1, j, word, k + 1))
            return true;

        if(dfs(board, visited, i - 1, j, word, k + 1))
            return true;

        visited[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char> >& board, string word){
        int l = word.size();
        if(l == 0) return true;

        int m = board.size();
        if(m == 0) return false;

        int n = board[0].size();
        if(n == 0) return false;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                map<int, map<int, bool> > visited;
                if(dfs(board, visited, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};

class Solution1{
public:
    bool isInBound(vector<vector<char> >& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }

    bool dfs(vector<vector<char> >& board, map<int, map<int, bool> >& visited, int i, int j, string& word, int k){
        if(board[i][j] != word[k])
            return false;

        if(k == word.size() - 1)
            return true;

        visited[i][j] = true;

        if(isInBound(board, i, j + 1) && !visited[i][j + 1] && dfs(board, visited, i, j + 1, word, k + 1))
            return true;

        if(isInBound(board, i, j - 1) && !visited[i][j - 1] && dfs(board, visited, i, j - 1, word, k + 1))
            return true;

        if(isInBound(board, i + 1, j) && !visited[i + 1][j] && dfs(board, visited, i + 1, j, word, k + 1))
            return true;

        if(isInBound(board, i - 1, j) && !visited[i - 1][j] && dfs(board, visited, i - 1, j, word, k + 1))
            return true;

        visited[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char> >& board, string word){
        int l = word.size();
        if(l == 0) return true;

        int m = board.size();
        if(m == 0) return false;

        int n = board[0].size();
        if(n == 0) return false;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                map<int, map<int, bool> > visited;
                if(dfs(board, visited, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};

int main(){
    char a[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    vector<vector<char> > board;
    for(int i = 0; i < 3; i++){
        vector<char> row = vector<char>(a[i], a[i] + 4);
        board.push_back(row);
    }

    Solution solution;
    cout << solution.exist(board, "ABCCED") << endl;
    cout << solution.exist(board, "SEE") << endl;
    cout << solution.exist(board, "ABCB") << endl;
    cout << solution.exist(board, "ABCESCFSADEE") << endl;
    return 0;
}

