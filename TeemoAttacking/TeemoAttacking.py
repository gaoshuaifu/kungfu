
# It is a variant of MergeIntervals
class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        if not timeSeries:
            return 0
        total_time = 0
        curr_start = timeSeries[0]
        curr_end = curr_start + duration
        for i in range(1, len(timeSeries)):
            next_start = timeSeries[i]
            next_end = next_start + duration
            if curr_end < next_start:
                total_time += curr_end - curr_start
                curr_start, curr_end = next_start, next_end
            else:
                curr_end = max(curr_end, next_end)
        total_time += curr_end - curr_start
        return total_time
