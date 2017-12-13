class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """

        self.vectors = [v1, v2]
        self.m = len(self.vectors)
        self.n = max(map(len, self.vectors))

        # Put the first column into queue.
        self.j = 0
        self.q = [
            self.vectors[i][self.j]
            for i in range(self.m) if self.j < len(self.vectors[i])
        ]

    def next(self):
        """
        :rtype: int
        """

        res = self.q.pop(0)

        # When queue is empty, put the next column into queue if it exists.
        if len(self.q) == 0:
            self.j += 1
            if self.j < self.n:
                self.q = [
                    self.vectors[i][self.j]
                    for i in range(self.m) if self.j < len(self.vectors[i])
                ]

        return res

    def hasNext(self):
        """
        :rtype: bool
        """

        return len(self.q) > 0
