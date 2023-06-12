# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left==right:
            return head

        node=baka=ListNode(None)
        baka.next,k=head,left-1

        while k:
            node=node.next
            k-=1
        last,e=node.next,right-left
        while e:
            dup=node.next
            node.next=last.next
            last.next=last.next.next
            node.next.next=dup
            e-=1
        return baka.next
        
