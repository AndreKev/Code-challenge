def func(i):
    delta = 1 + (4*i*(i+1)*(i+2))/3
    delta = delta**0.5
    return ((-1+delta)/2, (-1-delta)/2)

def triangular(i):
    return i*(i+1)/2

def tetra(i):
    return i*(i+1)*(i+2)/6

def check(val):
    if val == int(val):
        return True
    else:
        return False

# Celui-ci me donne les index des nombres en meme temps tri et tetra
for i in range(10000000):
    #i = int(input("Entrez le nombre a tester i :"))
    couple = func(i)
    if couple[0] ==  int(couple[0]):
        if not (check(triangular(couple[0])) and check(tetra(i))):
            print("ERROR")
        print("Triangulaire :", int(triangular(couple[0])), "Tetra :", tetra(i))
