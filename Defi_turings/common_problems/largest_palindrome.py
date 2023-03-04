# largest palindrome substring
def lps(string) -> list[str]:
    substrs = []    # contains indexes to the current lps
    l, ml = len(string), 0          # length of string and current max substr length
    for i in range(l):
        # Finding pair substrings
        c, j = i, i                 # start, end of the palindrome substring
        while c > -1 and j<l and string[c]==string[j]:
            c, j = c-1, j+1         # Find the longest palindrome
        mt = j-(c+1)    # get the length of the palindrome
        if mt > ml:
            substrs = [(c+1, j)]; ml = mt   # If we have found a new longest
        elif mt == ml:  substrs.append((c+1, j))   # Add the new one to the list
        # Finding pair substrings -  Analogical reasoning to previous
        c, k = i, i+1
        while c > -1 and k<l and string[c]==string[k]:
            c, k = c-1, k+1
        mt = k-(c+1)
        if mt > ml:
            substrs = [(c+1, k)]; ml = mt
        elif mt == ml:  substrs.append((c+1, j))    # Add te new one to the list
    return list(map(lambda pos: string[pos[0]:pos[1]], substrs))[0]

if __name__ == "__main__":
    string = "abab"
    print(lps(string))