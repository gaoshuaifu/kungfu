class Solution {
public:
    static const int DEAD = 0;
    static const int LIVE = 1;
    static const int LIVE_2_DEAD = 2;
    static const int LIVE_2_LIVE = 3;
    static const int DEAD_2_LIVE = 4;
    static const int DEAD_2_DEAD = 5;

    bool isLiveCell(vector<vector<int> >& board, int i, int j) {
        return (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) &&
               (board[i][j] == LIVE || board[i][j] == LIVE_2_DEAD || board[i][j] == LIVE_2_LIVE);
    }

    int countLiveNeighbors(vector<vector<int> >& board, int i, int j) {
        int count = 0;
        for(int di = -1; di <= 1; di++) {
            for(int dj = -1; dj <= 1; dj++) {
                if(di == 0 && dj == 0) {
                    continue;
                }
                count += isLiveCell(board, i + di, j + dj)? 1 : 0;
            }
        }
        return count;
    }

    void gameOfLife(vector<vector<int> >& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                bool live = isLiveCell(board, i, j);
                int count = countLiveNeighbors(board, i, j);
                if(live && count < 2)
                    board[i][j] = LIVE_2_DEAD;
                else if(live && (count == 2 || count == 3))
                    board[i][j] = LIVE_2_LIVE;
                else if(live && count > 3)
                    board[i][j] = LIVE_2_DEAD;
                else if(!live && count == 3)
                    board[i][j] = DEAD_2_LIVE;
                else
                    board[i][j] = DEAD_2_DEAD;
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == LIVE_2_DEAD || board[i][j] == DEAD_2_DEAD)
                    board[i][j] = DEAD;
                else
                    board[i][j] = LIVE;
            }
        }
    }
};
