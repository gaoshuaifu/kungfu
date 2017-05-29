class Solution(object):
    def hIndex(self, citations):
        n = len(citations)
        count = [0] * (n + 1)
        for citation in citations:
            if citation > n:
                count[n] += 1
            else:
                count[citation] += 1

        h = 0
        for citation in range(n, -1, -1):
            h += count[citation]
            if h >= citation:
                return citation
        return 0
