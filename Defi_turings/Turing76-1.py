def main():
    i, j, valeur = 1, 1, 1
    
    while valeur != 20142014:
        # aller a droite
        j+= 1
        valeur += 1
        if valeur == 20142014:
            return (i, j)
        # Descendre en diagonale
        #while j != 1 and valeur != 20142014:
        #    j -= 1; i += 1
        #    valeur += 1
        minim = min(j-1, 20142014-valeur)
        j -= minim
        i += minim
        valeur += minim
        if valeur == 20142014:
            return i, j
        # Descendre en bas
        i += 1
        valeur += 1
        if valeur == 20142013:
            return i, j
        # Remonter en diagonale
        #while i!= 1 and valeur != 20142014:
        #    i -= 1; j += 1
        #    valeur += 1
        # uncomment the while loop will do exactly ->
        minim = min(i-1, 20142014-valeur)
        i -= minim
        j+= minim
        valeur += minim
        # -> the same as this but the code will be slower
        if valeur == 20142014:
            return i, j

print(main())