class Solution(object):
    DIR = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]

    def in_bound(self, board, i, j):
        return i >= 0 and i < len(board) and j >= 0 and j < len(board[0])

    def count_mines(self, board, i, j):
        count = 0
        for di, dj in Solution.DIR:
            x, y = i + di, j + dj
            if self.in_bound(board, x, y) and board[x][y] == "M":
                count += 1
        return count

    def dfs(self, board, i, j, visited):
        if not self.in_bound(board, i, j) or (i, j) in visited:
            return

        visited.add((i, j))

        if board[i][j] == "M":
            board[i][j] = "X"
            return

        num_mines = self.count_mines(board, i, j)
        if num_mines == 0:
            board[i][j] = "B"
            for di, dj in Solution.DIR:
                x, y = i + di, j + dj
                self.dfs(board, x, y, visited)
        else:
            board[i][j] = str(num_mines)


    def updateBoard(self, board, click):
        if not board or not board[0]:
            return board
        visited = set()
        self.dfs(board, click[0], click[1], visited)
        return board
