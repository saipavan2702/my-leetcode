# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        runS=0
        def recur(node):
            nonlocal runS
            if not node:
                return
            
            recur(node.right)
            node.val=runS+node.val  
            runS=node.val
            recur(node.left)
        
        recur(root)
        return root
