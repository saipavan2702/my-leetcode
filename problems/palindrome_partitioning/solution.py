class Solution:
    def check(self,l,r,s):
        while(l<=r):
            if(s[l]!=s[r]):
                return 0
            l+=1
            r-=1
        return 1

    def recur(self,x,s,p,ans):
        n=len(s)
        if(x==n):
            ans.append(p[:])
            return
        for i in range(x,n):
            if(self.check(x,i,s)):
                p.append(s[x:i+1])
                self.recur(i+1,s,p,ans)
                p.pop()

    def partition(self, s: str) -> List[List[str]]:
        p=[]
        ans=[]
        self.recur(0,s,p,ans)
        return ans