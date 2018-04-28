class Solution(object):
    def addTwoNumbers(self, l1, l2):
        head = ListNode(None)
        tail = head 
        
        p1, p2 = l1, l2
        carry = 0
        while p1 or p2:
            total = 0
            if p1:
                total += p1.val
                p1 = p1.next
            if p2:
                total += p2.val
                p2 = p2.next
            total += carry
            
            digit = total % 10
            carry = total / 10
            
            tail.next = ListNode(digit)
            tail = tail.next
            
        if carry:
            tail.next = ListNode(carry)
        return head.next
