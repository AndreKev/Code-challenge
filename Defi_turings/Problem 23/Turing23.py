def Turing23(M, N):
    return fact(M+N)//(fact(M)*fact(N))

def fact(N):
    return 1 if N<1 else N*fact(N-1)

def main():
    print("Problem 23:", Turing23(30, 20))

if __name__ == "__main__":
    main()