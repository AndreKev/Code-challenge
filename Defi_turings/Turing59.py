# Avec les nombres parfaits, nous savons que
# le plus petit nombre dont la somme des diviseur strict est le nombre, c'est le nombre lui meme
# Nous pouvons obtenir la formule pour les parfaits impairs et pour les parfaits pairs

#  D'apres mersenne si M = 2**p-1 est premier alors M(M+1)/2 = 2**(p-1)x(2**p - 1) est parfait
#  496 = 1**3 + 3**3 + 5**3 + 7**3

# On va verifier uniquement pour les nombres pairs
# De facon descendante jusqu'au prochain nombre parfait
nombre = 666
def strict_factors(number):
    facts = []
    for i in range(1, int(number/2)+1):
        print(i)
        if i not in facts:
            if number%i == 0:
                p = 2
                f = i**p
                while number%f==0 and f!=1:
                    for j in facts:
                        facts.append(j*f)
                    facts.append(f)
                    p += 1
                    f = i**p
                facts.append(i)
        print(facts)
    return facts
"""    return sum(facts)

k = strict_factors
maxi = 0

ks = []
ps = []
pmax = 0
val = 0
for p in range(10, 10000):
    k = strict_factors(p)
    if k not in ks:
        ks.append(k)
        if k < 666:
            ps.append(p)
            if k > val:
                val = k
                pmax = p
print(pmax, val)"""

#print(ps)
"""for i in range(len(ks)):
    if ks[i] > 666:
        ks[i] = 0

for p in range(10, 666):
    k = strict_factors(p)
    if k == 666:
        print(p)"""

print(strict_factors(100))