class Solution:
    def makeStringsEqual(self, s: str, t: str) -> bool:
        return s==t or(int(s)>0 and int(t)>0)