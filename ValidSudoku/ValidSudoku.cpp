/*
 * time: O(n^2), space: O(1)
 */
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution{
public:
    bool isValidSudoku(vector<vector<char> >& board){
        assert(board.size() == 9);
        assert(board[0].size() == 9);
        for(int i = 0; i < 9; i++){
            int hasFound[9] = {0};
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c == '.')
                    continue;
                if(c < '0' || c > '9' || hasFound[c - '1'] == 1)
                    return false;
                hasFound[c - '1'] = 1;
            }
        }

        for(int j = 0; j < 9; j++){
            int hasFound[9] = {0};
            for(int i = 0; i < 9; i++){
                char c = board[i][j];
                if(c == '.')
                    continue;
                if(c < '0' || c > '9' || hasFound[c - '1'] == 1)
                    return false;
                hasFound[c - '1'] = 1;
            }
        }

        for(int i = 0; i < 9; i++){
            int hasFound[9] = {0};
            for(int j = 0; j < 9; j++){
                int k = i / 3 * 3 + j / 3;
                int l = i % 3 * 3 + j % 3;
                char c = board[k][l];
                if(c == '.')
                    continue;
                if(c < '0' || c > '9' || hasFound[c - '1'] == 1)
                    return false;
                hasFound[c - '1'] = 1;
            }
        }

        return true;
    }
};

int main(){
    int a[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    vector<vector<char> > board;
    for(int i = 0; i < 9; i++){
        vector<char> row = vector<char>(a[i], a[i] + 9);
        board.push_back(row);
    }

    Solution solution;
    cout << solution.isValidSudoku(board) << endl;

    return 0;
}

