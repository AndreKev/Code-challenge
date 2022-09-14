MAXDIGITS = 9

def generate(digits, prefix, divident):
    if divident>MAXDIGITS:
        return prefix
    else:
        for i in range(len(digits)):
            back = digits.pop()
            aux_digit = prefix*10+back
            if (aux_digit%divident==0):
                aux_digit = generate(digits, aux_digit, divident+1)
                if aux_digit != -1:
                    return aux_digit
                else:
                    digits.insert(0, back)
            else:
                digits.insert(0, back)
        else:
            return -1

def Turing26():
    digits = [i for i in range(1, 10)]
    return generate(digits, 0, 1)

def main():
    print("Problem 26:", Turing26())

if __name__ == "__main__":
    main()