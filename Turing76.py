i, j = 0, 0
val = 1
matrice = [[val]]

def mprint(matrice):
    print()
    for k in matrice:
        print(k)
        
def right(val):
    global i, j, matrice
    matrice[i].append(val)
    j += 1

def down(val):
    global i, j, matrice
    i += 1
    if len(matrice) == i:
        matrice.append([])
    matrice[i].append(val)

def diagup(val):
    global i, j, matrice
    i -= 1
    right(val)


def diagdown(val):
    global i, j, matrice
    j -= 1
    down(val)

def main():
    global i, j, matrice, val
    found = False
    search = 20142014
    print(matrice, (i, j))
    val += 1
    while val < 20142015 and not found:
        right(val)
        #mprint(matrice)
        if val == search:
            found = True
        val += 1
        while j > 0 and not found:
            diagdown(val)
            #mprint(matrice)
            if val == search:
                found = True
            val += 1
        if not found:
            down(val)
        #mprint(matrice)
        if val == search:
            found = True
        val += 1
        while i > 0 and not found:
            diagup(val)
            #mprint(matrice)
            if val == search:
                found = True
            val += 1
    print(i, j, matrice[i][j])

if __name__ == "__main__":
    main()
    pass
