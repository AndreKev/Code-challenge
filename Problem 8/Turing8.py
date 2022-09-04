def main():
    y = lambda x, r: (2*r)/(x*(x+1)) + (x-1)/3
    rsquares = []
    for min_side in range(10, 30):
        max_side = y(min_side, 6400)
        if max_side.is_integer():
            rsquares.append((min_side, max_side))
    # Now we look for the closest pair
    distance = float("inf")  # Just for example
    min_side = 0
    max_side = min_side + distance
    for m, n in rsquares:
        if n-m < distance:
            distance = n-m; 
            min_side = m; max_side = n
    print("The area is ", min_side*max_side)
    print("The sides are ", min_side, "and", max_side)

if __name__ == "__main__":
    main()