class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return self.solution(s, p)

    def solution(self, s, p, i=0, j=0):
        print("Entering with :", s[i:], p[j:], i, j)
        # set condition on j and i
        if p[j]=="$" and s[i]==p[j]:
            return 1
        elif p[j]=="$":
            return 0
        #
        if p[j]==".":
            if p[j+1]=="*":
                l = len(p)
                while j+3<l and p[j+3]=="*" and p[j]==p[j+2]:
                    j += 2
                if s[i]=="$":
                    return self.solution(s, p, i, j+2)
                val = self.solution(s, p, i+1, j)
                if val:
                    return 1
                else:
                    return self.solution(s, p, i, j+2)
            else:
                if s[i]=="$":
                    return 0
                return self.solution(s, p, i+1, j+1)
        else:
            print(p[j], end="")
            if p[j+1]=="*":
                l = len(p)
                while j+3<l and p[j+3]=="*" and p[j]==p[j+2]:
                    j += 2
                print("*\t", end="")
                if s[i]=="$":
                    print("$")
                    return self.solution(s, p, i, j+2)
                if p[j]==s[i]:
                    print(p[j], "ok")
                    val = self.solution(s, p, i+1, j)
                    if val:
                        return 1
                    else:
                        return self.solution(s, p, i, j+2)
                else:
                    return self.solution(s, p, i, j+2)
            else:
                if s[i]=="$":
                    return 0
                if p[j]==s[i]:
                    return self.solution(s,p,i+1,j+1)
                else:
                    return False

if __name__=="__main__":
    problem = Solution()
    s, p = "aa", "a"
    s += "$"
    p += "$"
    out = problem.solution(s,p)
    print("Value: ", out)