# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        self.ans=0
        def recur(root,s):
            if not root:
                return
            
            s*=10
            s+=root.val

            if not root.left and not root.right:
                self.ans+=s
                return
            
            recur(root.left,s)
            recur(root.right,s)
           
        
        recur(root,0)
        return self.ans