class Vector2D(object):
    def __init__(self, vec2d):
        """ Initialize your data structure here. vec2d: List[List[int]] """

        self.vec2d = vec2d
        self.x = 0
        self._find_next_list()

    def _find_next_list(self):
        while self.x < len(self.vec2d) and not self.vec2d[self.x]:
            self.x += 1
        self.y = 0

    def next(self):
        """ rtype: int """

        res = self.vec2d[self.x][self.y]

        self.y += 1
        if self.y == len(self.vec2d[self.x]):
            self.x += 1
            self._find_next_list()

        return res

    def hasNext(self):
        """ :rtype: bool """
        return self.x < len(self.vec2d) and self.y < len(self.vec2d[self.x])
