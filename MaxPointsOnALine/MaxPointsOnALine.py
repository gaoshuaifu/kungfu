class Point(object):
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution(object):
    def maxPoints(self, points):
        if not points:
            return 0

        import collections
        d = collections.defaultdict(int)
        res = 0
        for i in range(len(points)):
            d.clear()
            same_point = 0
            for j in range(i + 1, len(points)):
                dx = points[i].x - points[j].x
                dy = points[i].y - points[j].y
                if dx == 0 and dy == 0:
                    same_point += 1
                    continue
                slope = 'inf' if dx == 0 else dy * 1.0 / dx
                d[slope] += 1
            other_point = max(d.values()) if d.values() else 0
            res = max(res, other_point + same_point + 1)
        return res
