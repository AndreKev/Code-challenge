# Apllication de l'exercice 20 de Turing
#
# Ma pile
class Hydre(object):
    def __init__(self, head, attack=0):
        self.monsters = [head]
        self.attacks = attack
    
    def attack(self):
        self.attacks += 1
        self.monsters[-1] -= 1
        # Kill the monster if it has no more head
        if self.monsters[-1] == 0:
            del self.monsters[-1]
        elif self.monsters[-1] == 1:
            self.attacks += self.attacks + 1
            del self.monsters[-1]
        else:
            # Add copies of the attacked monster
            self.monsters.extend([self.monsters[-1] for copy in range(self.attacks)])
    
    def isalive(self):
        return len(self.monsters) != 0

    def __str__(self):
        return f"{str(self.monsters)}, {str(self.attacks)}"

def main(heads):
    import time
    hydre = Hydre(heads)
    t = time.time()
    while hydre.isalive():
        #print(hydre)
        hydre.attack()
    print(hydre)
    print("The time is :", time.time()-t)

if __name__ == "__main__":
    main(5)