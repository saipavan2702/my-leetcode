class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if s==goal:
            return len(set(s))<len(goal)
        n,p=len(s),len(goal)
        if n!=p:
            return False
        dif,id=0,[]
        for i in range(n):
            if s[i]!=goal[i]:
                dif+=1
                id.append(i)
        return dif==2 and s[id[0]]==goal[id[1]] and s[id[1]]==goal[id[0]]
        
                

