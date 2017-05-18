class RandomizedSet(object):

    def __init__(self):
        self.a = []
        self.d = {}

    def insert(self, val):
        if val in self.d:
            return False

        self.a.append(val)
        self.d[val] = len(self.a) - 1
        return True

    def remove(self, val):
        if val not in self.d:
            return False
        idx = self.d[val]
        last = self.a[-1]
        self.a[idx] = last
        self.d[last] = idx
        self.a.pop()
        self.d.pop(val)
        return True

    def getRandom(self):
        import random
        return random.choice(self.a)
