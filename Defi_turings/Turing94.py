def trend(integer):
    expr = str(integer).replace("0","")
    somme = 0
    for i in expr:
        somme += int(i)**2
    #print(expr, somme)
    return trend(somme) if (somme not in [89, 1]) else somme

if __name__ == "__main__":
    i = 1
    nombres = 5000000
    while i <= 5000000:
        if trend(i) == 1:
            nombres -= 1
        i += 1
    print("Le nombre est :", nombres)
