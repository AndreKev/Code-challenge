class Turing193:
    def __init__(self, ):
        self.known = {}
        self.premiers = []

    def permutation(self, number):
        if number in self.known.keys():
            return self.known[number]
        if number < 4: return 0
        somme = 0
        for i in self.premiers:
            #print("i is",i)
            #print("k is ", k)
            space = number
            if space == i:
                #print(space, "equal to", i)
                somme += 1
            elif space > i:
                #print(space, "greater than", i)
                somme += 1 + self.permutation(space-i)
            else:
                break
        return somme

    def solve(self, maximum):
        condition = True # meaning that the condition is not satisfied
        number = 2
        while condition:
            self.known[number] = self.permutation(number)
            # The condition to exit
            if self.known[number] > maximum:
                condition = not condition
            # incrementing 
            print(number, self.known[number])
            number += 1
        return number-1
    
    def load_premiers(self, number):
        charged = self.premiers
        for num in range(2, number):
            i = 0
            divisible = False
            length = len(charged)
            root =  number**0.5
            while i<length and not divisible and charged[i]<root:
                if num%charged[i]==0:
                    divisible = True
                i += 1
            if not divisible:
                charged.append(num)


if __name__ == "__main__":
    problem = Turing193()
    problem.load_premiers(100)
    print(problem.premiers)
    number = int(input("For which number do you want to solve the question : "))
    print("The solution to the problem is ", problem.solve(number))
    print(problem.known)