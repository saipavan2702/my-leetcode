# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        stack=[]

        node=head
        len=0
        prev=None

        while node: 
            temp=node.next
            node.next=prev
            prev=node
            node=temp
            len+=1
        
        can=[0]*len
        head=prev

        i=len-1
        while head:
            while stack and stack[-1]<=head.val:
                stack.pop()

            if stack:
                can[i]=stack[-1]
            i-=1
            stack.append(head.val)
            head=head.next
        return can