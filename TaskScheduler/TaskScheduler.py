class Solution(object):
    def leastInterval(self, tasks, n):
        from collections import Counter
        task_counts = collections.Counter(tasks).values()
        m = max(task_counts)
        l = task_counts.count(m)
        return max(len(tasks), (m - 1) * (n + 1) + l)
