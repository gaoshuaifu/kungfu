class Solution(object):
    def maxCount(self, m, n, ops):
        ops.append([m, n])
        min_x = min([op[0] for op in ops])
        min_y = min([op[1] for op in ops])
        return min_x * min_y
