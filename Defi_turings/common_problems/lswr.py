class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        occurence = {}
        length = 0
        start = end = 0
        l = len(s)
        while end<l:
            if occurence.get(s[end], 0):
                temp_length = end-start
                if temp_length > length:
                    length = temp_length
                while s[start]!=s[end]:
                    occurence[s[start]] = 0
                    start += 1
                start += 1
            else:
                occurence[s[end]] = 1 
            end += 1
        temp_length = end-start
        if temp_length>length:
            return temp_length
        else:
            return length
out = Solution().lengthOfLongestSubstring("pwwkew")
print(out)