## First approach
def solution1(a, b):
    numbers = [i**j for i in range(2,a+1)
                    for j in range(2,b+1)
    ]
    uniques = set(numbers)
    return len(uniques)

## Second approach
class Node:
    def __init__(self):
        self.head = None
        self.lson = None
        self.rson = None

    def rinsert(self, value):
        if self.head is None:
            self.head = value
            return 1
        else:
            if value > self.head:
                if self.rson is None:
                    self.rson = Node()
                return self.rson.insert(value)
            elif value < self.head:
                if self.lson is None:
                    self.lson = Node()
                return self.lson.insert(value)
            else:
                return 0

    def tinsert(self, value):
        p = self
        inserted = False
        while not inserted and p is not None:
            if p.head is None:
                p.head = value
                inserted = True
            else:
                if value > p.head:
                    if p.rson is None:
                        p.rson = Node()
                    p = p.rson
                elif value < p.head:
                    if p.lson is None:
                        p.lson = Node()
                    p = p.lson
                else:
                    p = None
        return inserted
class Tree:
    def __init__(self):
        self.node = Node()
        self.size = 0

    def __len__(self):
        return self.size

    def insert(self, val):
        self.size += self.node.tinsert(val)

def solution2(a, b):
    tree = Tree()
    for i in range(2, a+1):
        for j in range(2, b+1):
            tree.insert(i**j)
    return len(tree)

# Tests
a, b = 500,500
print("Turing 29: ", solution1(a,b))
print("Turing 29: ", solution2(a,b))