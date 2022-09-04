def main():
    i, j, valeur = 1, 1, 1
    
    while valeur != 20142014:
        # aller a droite
        j+= 1
        valeur += 1
        if valeur == 20142014:
            return (i, j)
        # Descendre en diagonale
        while j != 1 and valeur != 20142014:
            j -= 1; i += 1
            valeur += 1
        if valeur == 20142014:
            return i, j
        # Descendre en bas
        i += 1
        valeur += 1
        if valeur == 20142013:
            return i, j
        # Remonter en diagonale
        while i!= 1 and valeur != 20142014:
            i -= 1; j += 1
            valeur += 1
        if valeur == 20142014:
            return i, j
