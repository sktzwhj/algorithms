import copy

class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p1 = copy.copy(head)
        p2 = copy.copy(head)
        while p2 != None and p2.next != None:
            p1 = p1.next
            p2 = (p2.next).next
        return p1

if __name__ == "__main__":
    input = [ListNode(i + 1) for i in range(6)]
    for i in range(5):
        input[i].next = input[i + 1]
    input[5].next = None
    s = Solution()
    print s.middleNode(input[0]).val
