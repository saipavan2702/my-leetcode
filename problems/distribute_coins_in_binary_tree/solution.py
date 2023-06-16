# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        need=0
        def recur(node):
            if not node:
                return 0
            nonlocal need

            ls=recur(node.left)
            rs=recur(node.right)
            need+=abs(ls)+abs(rs)

            return node.val+ls+rs-1
        recur(root)
        return need