import collections

Cell = collections.namedtuple('Cell', ['x', 'y'])

class Solution(object):
    def _next_cells(self, cell):
        return [
            Cell(cell.x - 1, cell.y - 2),
            Cell(cell.x + 1, cell.y - 2),
            Cell(cell.x - 1, cell.y + 2),
            Cell(cell.x + 1, cell.y + 2),
            Cell(cell.x - 2, cell.y - 1),
            Cell(cell.x + 2, cell.y - 1),
            Cell(cell.x - 2, cell.y + 1),
            Cell(cell.x + 2, cell.y + 1),
        ]

    def knight_journey(self, start, end, obstacles):
        jumps = 0;
        currQ = list()
        visited = set()

        currQ.append(start)
        visited.add(start)

        while len(currQ):
            nextQ = list()
            while len(currQ):
                cell = currQ.pop(0)
                if cell == end:
                    return jumps
                for next_cell in self._next_cells(cell):
                    if next_cell not in visited and next_cell not in obstacles:
                        nextQ.append(next_cell)
                        visited.add(next_cell)
            currQ = nextQ
            jumps += 1
        return jumps

def main():
    solution = Solution()
    start = Cell(0, 0)
    end = Cell(3, 2)
    obstacles = set([Cell(-1, 2), Cell(0, 2), Cell(1, 1), Cell(1, 2), Cell(2, 0), Cell(2, 1), Cell(2, -1)])
    jumps = solution.knight_journey(start, end, obstacles)
    print(jumps)

if __name__ == "__main__":
    main()
