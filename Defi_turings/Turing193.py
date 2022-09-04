class Turing193:
    def __init__(self):
        self.known = {}

    def permutation(self, number):
        if number in self.known.keys():
            return self.known[number]
        if number < 3: return 0
        if number < 7: 
            number -= 2
            return number*(number+1)//2
        somme = 0
        for i in range(3, number+1):
            #print("i is",i)
            for k in range(0, number-i+1):
                #print("k is ", k)
                space = number-k
                if space == i:
                    #print(space, "equal to", i)
                    somme += 1
                elif space > i:
                    #print(space, "greater than", i)
                    somme += 1 + self.permutation(space-i-1)
        return somme

    def solve(self, number):
        for number in range(3, number+1):
            self.known[number] = self.permutation(number)
        return self.known[number]+1

if __name__ == "__main__":
    problem = Turing193()
    number = int(input("For which number do you want to solve the question : "))
    print("The solution to the problem is ", problem.solve(number))