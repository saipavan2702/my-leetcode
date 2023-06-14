# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        INF=10**9
        need,self.prev=INF,None
        def recur(node):
            if not node:
                return
            nonlocal need
            
            recur(node.left)
            if self.prev:
                need=min(need,node.val-self.prev.val)
            self.prev=node
            recur(node.right)
        recur(root)
        return need

