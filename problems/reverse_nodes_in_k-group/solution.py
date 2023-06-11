# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        baka=ListNode(-1,head)
        prev=baka

        node=head
        stack=[]
        while node:
            stack.append(node)
            node=node.next
            if(len(stack)==k):
                while len(stack):
                    curr=stack[-1]
                    stack.pop()
                    prev.next=curr
                    prev=curr
                prev.next=node
        return baka.next
            
            
            
