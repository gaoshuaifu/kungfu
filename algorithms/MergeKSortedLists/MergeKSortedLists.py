class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        head = tail = ListNode(0)

        from heapq import *        
        heap = [(node.val, node) for node in lists if node]
        heapify(heap)
    
        while heap:
            val, node = heappop(heap)
            tail.next = node
            if node.next:
                heappush(heap, (node.next.val, node.next))
            tail = tail.next
                
        return head.next
        
