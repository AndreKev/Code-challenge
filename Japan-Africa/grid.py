from turtle import *
# changer la vitesse de la tortue
# speed(int)        entre 0 et 10.

# Pour mettre la tortue a la vitesse maximale
# speed(str)
speed("fastest")

def rectangle(m, n):
    forward(m)  # premiere etape
    right(90)
    forward(n)  # Deuxieme etape
    right(90)
    forward(m)  # Troisieme etape
    right(90)
    forward(n)  # Quatrime etape
    right(90)

def carre(cote_unique):
    rectangle(cote_unique, cote_unique)

# dessiner une ligne avec n carre
def ligne(n, taille):
    # Je dois utiliser une boucle qui va dessiner tous ces carres
    for colonne in range(n):
        pendown()       # mettre la tortue sur la toille
        carre(taille)   # desinner le carre maintenant que la tortue est sur la toile
        # position suivante
        penup()
        forward(taille) # Nous le mettons a la postion souhaitee
    # Nous allons utiliser backward(int)
    backward(taille*n)      # for colonne in range(n): backward(taille)
    pendown()   # Remettre la tortue sur la toile a la fin
    
# La grille en entiere
def grid(m, n, taille):
    for line in range(m):
        ligne(n, taille)    # dessiner la premiere ligne
        # Passer a la position suivante pour la prochaine
        penup()
        right(90)       # en bas -> vers la droite de 90
        forward(taille)
        left(90)
        pendown()
    # replacons la tortue au bon endroit
    penup()     # lever la tortue
    right(90)
    backward(taille*m)
    left(90)
    pendown()


grid(20, 30, 20)

# Pour pouvoir visualiser le resultat
input()