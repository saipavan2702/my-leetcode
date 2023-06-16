# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, node: TreeNode, distance: int) -> int:
        graph=defaultdict(list)
        leaves=[]
        cn=0

        def recur(node,parent):
            if not node:
                return
            
            if not node.left and not node.right:
                leaves.append(node)

            graph[node].append(parent)
            graph[parent].append(node)

            recur(node.left,node)
            recur(node.right,node)
        
        recur(node,None)
        
        for leaf in leaves:
            queue=[(leaf,1)]
            seen=set()
            while queue:
                node,dist=queue.pop(0)
                seen.add(node)
                if dist>distance:
                    break
                for nei in graph[node]:
                    if nei and nei not in seen:
                        seen.add(nei)
                        queue.append((nei,dist+1))
                        if nei in leaves and dist<=distance:
                            cn+=1

        return cn//2

