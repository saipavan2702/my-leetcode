class Solution:
    def alertNames(self, N: List[str], T: List[str]) -> List[str]:
        adj=defaultdict(list)
        for n,t in zip(N,T):
            x=int(t[:2])*60+int(t[3:])
            adj[n].append(x)
        
        ans=[]
        for n,t in adj.items():
            t.sort()
            for i in range(len(t)-2):
                if t[i+2]-t[i]<=60:
                    ans.append(n)
                    break

        return sorted(ans)

        