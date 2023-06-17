class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        stack=[float('inf')]
        can=0
        for i in arr:
            while stack and stack[-1]<=i:
                node=stack.pop()
                if stack:
                    can+=node*min(stack[-1],i)
            stack.append(i)
        
        while len(stack)>2:
            can+=stack.pop()*stack[-1]
        return can