class ListIterator(object):
    def __init__(self, my_list, pos):
        self.my_list = my_list
        self.pos = pos

    def has_next(self):
        return self.pos < len(self.my_list)

    def next(self):
        res = self.my_list[self.pos]
        self.pos += 1
        return res

    def map(self, fn):
        return Map(self, fn)

    def clone(self):
        return ListIterator(self.my_list, self.pos)

class Map(object):
    def __init__(self, it, fn):
        self.it = it.clone()
        self.fn = fn

    def has_next(self):
        return self.it.has_next()

    def next(self):
        return self.fn(self.it.next())

    def map(self, fn):
        return Map(self, fn)

    def clone(self):
        return Map(self.it, self.fn)

def main():
    my_list = [0, 1, 2, 3]

    it = ListIterator(my_list, 0)
    mit = it.map(lambda x : x + 1)
    mmit = mit.map(lambda x : x * x)

    while it.has_next():
        print(it.next())

    while mit.has_next():
        print(mit.next())

    while mmit.has_next():
        print(mmit.next())

if __name__ == "__main__":
    main()
