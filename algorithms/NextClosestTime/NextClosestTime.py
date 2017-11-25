class Solution(object):
    def nextClosestTime(self, time):
        import itertools
        res = start = 60 * int(time[:2]) + int(time[3:])
        min_elapsed = 24 * 60
        allowed = {int(x) for x in time if x != ':'}
        for h1, h2, m1, m2 in itertools.product(allowed, repeat=4):
            hours, mins = 10 * h1 + h2, 10 * m1 + m2
            if hours < 24 and mins < 60:
                cur = hours * 60 + mins
                elapsed = (cur - start) % (24 * 60)
                if 0 < elapsed < min_elapsed:
                    res = cur
                    min_elapsed = elapsed
        return "{:02d}:{:02d}".format(*divmod(res, 60))
