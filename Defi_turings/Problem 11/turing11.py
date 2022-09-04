import time
# Here I use a very sophisticated algorithm
# In the analysis I determine iteratively every digit
def algo1():
    numbers = []
    for a in range(0, 9):
        count = 0
        digits = [0 for i in range(6)]
        digits[5] = a
        prime = 0
        while count < 5:
            index = 4 - count
            aux = digits[index+1]*a+prime
            digits[index] = (aux)%10
            prime = int(str(aux)[0]) if len(str(aux)) == 2 else 0
            
            count+=1
        if not (prime or digits[0]*a>a):
            numbers.append(int("".join([str(num) for num in digits])))
    
    return sum(numbers)

# Here I use a brute force algorithm which is far more slower
def algo2():
    numbers = []
    for i in range(100000, 999999):
        if i*int(str(i)[-1]) == int(str(i)[-1]+str(i)[:-1]):
            numbers.append(i)

    return sum(numbers)

if __name__ ==  "__main__":
    
    # First algorithm
    t = time.time()
    print("1: first algorithm technic")
    print("result         : ", algo1())
    time1 = time.time()-t
    print("Execution time : ", time1)

    # To seperate output
    print("\n")

    # Second algorithm
    t = time.time()
    print("2: second algorithm technic")
    print("result         : ", algo2())
    time2 = time.time()-t
    print("Execution time : ", time2)

    # Speed ratio
    print()
    print(f"The first one is {time2/time1}times faster than the second one")