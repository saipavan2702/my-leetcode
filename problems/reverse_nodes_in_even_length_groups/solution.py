# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n,node=0,head
        while node:n,node=n+1,node.next

        k,node=0,head
        while n:
            k+=1
            size=min(n,k)
            stack=[]
            if not size&1:
                curr=node
                for _ in range(size):
                    stack.append(curr.val)
                    curr=curr.next
            for _ in range(size):
                if stack:node.val=stack.pop()
                node=node.next
            n-=size
        return head
            