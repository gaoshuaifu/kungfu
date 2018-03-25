class Vector2D(object):
    def __init__(self, vec2d):
        """ Initialize your data structure here. vec2d: List[List[int]] """

        self.vec2d = vec2d
        self.i = 0
        self._find_next_list()

    def _find_next_list(self):
        while self.i < len(self.vec2d) and not self.vec2d[self.i]:
                self.i += 1
        self.j = 0

    def next(self):
        """ rtype: int """

        res = self.vec2d[self.i][self.j]

        self.j += 1
        if self.j == len(self.vec2d[self.i]):
            self.i += 1
            self._find_next_list()

        return res

    def hasNext(self):
        """ :rtype: bool """
        return self.i < len(self.vec2d) and self.j < len(self.vec2d[self.i])
