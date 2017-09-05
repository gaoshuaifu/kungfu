class Solution(object):
    def copyRandomList(self, head):
        d = {}
        node = head
        while node:
            d[node] = RandomListNode(node.label)
            node = node.next

        node = head
        while node:
            d[node].next = d.get(node.next)
            d[node].random = d.get(node.random)
            node = node.next
        return d.get(head)
