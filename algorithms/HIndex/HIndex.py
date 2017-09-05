class Solution(object):
    def hIndex(self, citations):
        n = len(citations)

        # Create a new vector of size n+1.
        # The h-index can be at most n, when all of his papers have citations >= n.
        count = [0] * (n + 1)
        for citation in citations:
            # Put all citation > n in the same bucket.
            if citation > n:
                count[n] += 1
            else:
                count[citation] += 1

        # Scan citation from right (n) to left (0).
        papers = 0
        for citation in range(n, -1, -1):
            papers += count[citation]
            if papers >= citation:
                return citation
        return 0
