from math import log10
def Turing25(MAXDIGITS):
    a = b = 1
    c = a+b
    rank = 3
    while(log10(c)+1<MAXDIGITS):
        a, b = b, c
        c = a+b
        rank += 1
    return rank

def main():
    print("Problem 25:", Turing25(2013))

if __name__ == "__main__":
    main()