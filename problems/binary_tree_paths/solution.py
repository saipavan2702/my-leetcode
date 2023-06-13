# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        need=[]
        def recur(node,curr):
            if not node:
                return 
            if not node.left and not node.right:
                need.append(curr)
                return
            if node.left:
                recur(node.left,curr+"->"+str(node.left.val))
            if node.right:
                recur(node.right,curr+"->"+str(node.right.val))
        recur(root,str(root.val))
        return need
    
