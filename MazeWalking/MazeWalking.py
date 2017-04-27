
def valid_position(board, i, j):
    return i >= 0 and i < len(board) and j >= 0 and j < len(board[0]) and board[i][j] == 0

def reach_destination(board, i, j):
    return i == len(board) - 1 and j == len(board[0]) - 1

def dfs(board, i, j, visited, path):
    if (i, j) in visited or not valid_position(board, i, j):
        return False

    if reach_destination(board, i, j):
        path.append((i, j))
        return True

    path.append((i, j))
    visited.add((i, j))

    if dfs(board, i + 1, j, visited, path):
        return True

    if dfs(board, i - 1, j, visited, path):
        return True

    if dfs(board, i, j + 1, visited, path):
        return True

    if dfs(board, i, j - 1, visited, path):
        return True

    path.pop()
    return False

def solve(board):
    print 'here'
    visited = set()
    path = list()
    dfs(board, 0, 0, visited, path)
    return path

def main():
    board = [
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 1, 0],
        [0, 0, 1, 0, 1, 1, 0],
        [0, 0, 1, 0, 1, 0, 1],
        [1, 1, 1, 0, 0, 0, 0]
    ]

    print solve(board)

main()
