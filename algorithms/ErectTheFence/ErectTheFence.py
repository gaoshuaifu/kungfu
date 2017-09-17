class Solution(object):
    def _orientation(self, p, q, r):
        """ The orientation from vector pq to vector qr.

        The cross product of vectors pq and qr vec(pq) x vec(qr).
        > 0 counterclockwise
        = 0 straight
        < 0 clockwise
        """

        return (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x)

    def outerTrees(self, points):
        if len(points) < 4:
            return points

        # Sort points on the basis of their x values. If two points have the same
        # x values, the points are sorted based on their y values.
        points = sorted(points, cmp=lambda p,q: p.x - q.x if p.x != q.x else p.y - q.y)

        stk = []
        for point in points:
            while len(stk) >= 2 and self._orientation(stk[-2], stk[-1], point) < 0:
                stk.pop()
            stk.append(point)
        stk.pop()

        for point in points[::-1]:
            while len(stk) >= 2 and self._orientation(stk[-2], stk[-1], point) < 0:
                stk.pop()
            stk.append(point)
            print point.x,point.y
        stk.pop()

        return list(set(stk))
