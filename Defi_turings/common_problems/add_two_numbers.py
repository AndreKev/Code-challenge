# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def from_list(self, list):
        p = self
        for val in list:
            p.val = val
            p.next = ListNode()
            q = p
            p = p.next
        del p
        q.next = None
        return self
    
    def __str__(self):
        p = self
        out = ""
        while p is not None:
            out += str(p.val) + " "
            p = p.next
        return out

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cache1 = cache0 = 0
        head = ListNode(); current = head
        while not(l1 is None and l2 is None):
            l1value = l1.val if l1 else 0
            l2value = l2.val if l2 else 0
            cache0 = l1value + l2value + cache1
            cache1 = cache0//10
            cache0 %= 10
            # Insert
            current.next = ListNode(cache0)
            current = current.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        if cache1:
            current.next = ListNode(cache1)
        return head.next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cache1 = cache0 = 0
        result = ListNode(); head = result
        while l1 is not None and l2 is not None:
            cache0 = l1.val + l2.val + cache1
            cache1 = cache0//10
            cache0 %= 10
            #print("r", cache0, cache1)
            # store the result
            result.val = cache0
            # prepare next
            q = result
            result.next = ListNode()
            result = result.next
            # To the next
            l1 = l1.next
            l2 = l2.next
        if l1 is not None:
            l2 = l1
        while l2 is not None:
            cache0 = l2.val + cache1
            cache1 = cache0//10
            cache0 %= 10
            #print("r", cache0, cache1)
            # store the result
            result.val = cache0
            q = result
            result.next = ListNode()
            result = result.next
            # To the next
            l2 = l2.next
        if cache1:
            result.val = cache1
        if q.next.val==0: q.next = None
        return head

if __name__ == "__main__":
    solution = Solution()
    l1 = ListNode().from_list([9,1,6])
    l2 = ListNode().from_list([0])

    print(l1)
    print(l2)
    print(solution.addTwoNumbers(l1, l2))
