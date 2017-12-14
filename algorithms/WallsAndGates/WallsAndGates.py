DIRS = ((1, 0), (0, 1), (-1, 0), (0, -1))
INF = 2 ** 31 - 1
class Solution(object):

    def wallsAndGates(self, rooms):
        m = len(rooms)
        if m == 0: return

        n = len(rooms[0])
        if n == 0: return

        # Put gates into queue.
        q = [(i, j) for i in range(m) for j in range(n) if rooms[i][j] == 0]

        # Go through all INF, assign distance
        while q:
            i, j = q.pop(0)
            for di, dj in DIRS:
                ni, nj = i + di, j + dj
                if ni in range(m) and nj in range(n) and rooms[ni][nj] == INF:
                    rooms[ni][nj] = rooms[i][j] + 1
                    q.append((ni, nj))
