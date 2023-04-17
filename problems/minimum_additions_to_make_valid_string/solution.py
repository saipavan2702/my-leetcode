class Solution:
    def addMinimum(self, s: str) -> int:
        i=0
        need=0
        while i<len(s):
            if s[i:i+3] == "abc":
                i+=3  
            elif s[i:i+2] in ["ab","ac","bc"]:
                need+=1
                i+=2
            else:
                need+=2
                i+=1
        return need
                    