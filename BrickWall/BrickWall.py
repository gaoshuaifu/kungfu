class Solution(object):
    def leastBricks(self, wall):
        from collections import defaultdict
        # d: length from the left => number of brick edges
        d = defaultdict(int)
        for row in wall:
            w = 0
            for width in row[:-1]:
                w += width
                d[w] += 1
        edges = max(d.values()) if d else 0
        return len(wall) - edges
