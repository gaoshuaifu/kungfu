class Node(object):
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache(object):

    def __init__(self, capacity):
        self.capacity = capacity
        self.mp = {}
        self.head, self.tail = Node(0, 0), Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key):
        if key not in self.mp:
            return -1

        node = self.mp[key]
        self._remove(node)
        self._add_to_front(node)
        return node.val

    def put(self, key, value):
        if key in self.mp:
            node = self.mp[key]
            self._remove(node)
            del self.mp[key]

        node = Node(key, value)
        self._add_to_front(node)
        self.mp[key] = node

        if len(self.mp) > self.capacity:
            node = self.tail.prev
            self._remove(node)
            del self.mp[node.key]

    def _remove(self, node):
        prev = node.prev
        next = node.next
        prev.next = next
        next.prev = prev

    def _add_to_front(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next = node
        node.next.prev = node
