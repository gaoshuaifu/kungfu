class Solution(object):
    def findMinDifference(self, timePoints):
        ts = [t.split(':') for t in timePoints]
        ts = sorted([(int(t[0]) * 60 + int(t[1])) for t in ts])
        min_diff, n = 60 * 24, len(ts)
        for i in range(len(ts) - 1):
            min_diff = min(min_diff, ts[i + 1] - ts[i])
        min_diff = min(min_diff, ts[0] + 60 * 24 - ts[-1])
        return min_diff
