class Solution(object):
    def mergeTwoLists(self, l1, l2):
        head = ListNode(None)
        tail = head
        
        p1, p2 = l1, l2
        while p1 and p2:
            if p1.val <= p2.val:
                tail.next = p1
                p1 = p1.next
            else:
                tail.next = p2
                p2 = p2.next
            tail = tail.next
        tail.next = p1 if p1 else p2
        return head.next
