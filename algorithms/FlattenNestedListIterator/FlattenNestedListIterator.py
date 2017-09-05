class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """

        self.stk = []
        for ni in nestedList[::-1]:
            self.stk.append(ni)

    def next(self):
        """
        :rtype: int
        """

        return self.stk.pop().getInteger()

    def hasNext(self):
        """
        :rtype: bool
        """

        while self.stk:
            if self.stk[-1].isInteger():
                return True
            top = self.stk.pop()
            for ni in top.getList()[::-1]:
                self.stk.append(ni)
        return False
