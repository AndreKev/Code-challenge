def fact(n):
    factorial = 1
    while n > 1:
        factorial *= n
        n -= 1
    return factorial

def main():
    n = 2013
    factn = fact(n)
    output = 0
    while factn:
        output += factn%10
        factn //= 10
    print("Problem 6:", output)

if __name__ == "__main__":
    main()