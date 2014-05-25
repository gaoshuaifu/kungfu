/*
 * time: O(1), space: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool isValid(vector<vector<char> > &board, int row, int col){
		for(int i = 0; i < 9; i++){
			if(i == row)	
				continue;
			if(board[i][col] == board[row][col])
				return false;
		}
		
		for(int j = 0; j < 9; j++){
			if(j == col)
				continue;
			if(board[row][j] == board[row][col])
				return false;
		}
		
		for(int i = 0; i < 9; i++){
			int x = row / 3 * 3 + i / 3;
			int y = col / 3 * 3 + i % 3;
			if(x == row && y == col)
				continue;
			if(board[x][y] == board[row][col])
				return false;
		}
		return true;
	}
	
	bool solveSudokuHelper(vector<vector<char> >& board){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.')
					continue;
				
				for(char c = '1'; c <= '9'; c++){
					board[i][j] = c;
					if(isValid(board, i, j) && solveSudokuHelper(board))
						return true;
					board[i][j] = '.';
				}
				return false;	
			}
		}
		return true;
	}
	
	void solveSudoku(vector<vector<char> >& board){
		solveSudokuHelper(board);
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
	solution.solveSudoku(board);
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	return 0;
}
