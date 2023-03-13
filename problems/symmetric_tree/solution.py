# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return 0
        
        def recur(left,right):
            if not left and not right:
                return 1
            if not left or not right or left.val!=right.val:
                return 0
            return recur(left.left,right.right) and recur(left.right,right.left)

        return recur(root.left,root.right)