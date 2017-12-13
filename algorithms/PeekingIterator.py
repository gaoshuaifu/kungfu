class PeekingIterator(object):
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """

        self.iterator = iterator
        self.buf = self._getNext()

    def _getNext(self):
        return self.iterator.next() if self.iterator.hasNext() else None

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """

        return self.buf

    def next(self):
        """
        :rtype: int
        """

        res = self.buf
        self.buf = self._getNext()
        return res

    def hasNext(self):
        """
        :rtype: bool
        """

        return self.buf is not None
