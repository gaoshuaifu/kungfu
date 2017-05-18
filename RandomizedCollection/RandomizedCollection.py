class RandomizedCollection(object):

    def __init__(self):
        self.a = []
        self.d = collections.defaultdict(set)

    def insert(self, val):
        self.a.append(val)
        self.d[val].add(len(self.a) - 1)
        return len(self.d[val]) == 1

    def remove(self, val):
        if val not in self.d:
            return False
        idx = self.d[val].pop()
        last = self.a[-1]
        self.a[idx] = last
        self.d[last].add(idx)
        self.d[last].discard(len(self.a) - 1)
        self.a.pop()
        if len(self.d[val]) == 0:
            del self.d[val]
        return True

    def getRandom(self):
        import random
        return random.choice(self.a)
