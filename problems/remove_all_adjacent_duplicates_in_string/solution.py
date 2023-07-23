class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack,n=[],len(s)
        for x in range(0,n):
            if  not stack:
                stack.append(s[x])
            else:
                if stack[-1]==s[x]:
                    stack.pop()
                else:
                    stack.append(s[x])
        ans=""
        while stack:
            ans=stack.pop()+ans
        return ans

